#ifndef PROJECT1LEXER_PARSER_H
#define PROJECT1LEXER_PARSER_H
#include <vector>
#include "Token.h"
#include "DatalogProgram.h"
#include <iostream>

class Parser {
private:
    vector<Token> tokens;
    unsigned int currTokenIndex = 0;
    DatalogProgram program;

    string getPrevTokenContents() {
        if (currTokenIndex < 0) throw "Out of bounds when checking";
        return tokens.at(currTokenIndex - 1).getContents();
    }

    string getCurrTokenContents() {
        if (currTokenIndex >= tokens.size()) throw "Out of bounds when checking";
        return tokens.at(currTokenIndex).getContents();
    }

public:
    Parser(const vector<Token>& tokens) : tokens(tokens) {}

    void DataLog() {
        //SCHEMES COLON scheme schemeList FACTS COLON factList RULES COLON ruleList QUERIES COLON query queryList EOF
        match(SCHEMES);
        match(COLON);
        scheme();
        schemeList();
        match(FACTS);
        match(COLON);
        factList();
        match(RULES);
        match(COLON);
        ruleList();
        match(QUERIES);
        match(COLON);
        query();
        queryList();
        match(END_OF_FILE);
    }

    DatalogProgram run() {
        DataLog();
        return program;
    }

    TokenType currTokenType() const {
        if (currTokenIndex >= tokens.size()) return UNDEFINED;
        return tokens.at(currTokenIndex).getType();
    }

    void advanceToken() {
        ++currTokenIndex;
    }

    void throwError() {
        if (currTokenIndex >= tokens.size()) throw tokens.at(tokens.size() - 1);
        throw tokens.at(currTokenIndex);
    }

    void match(TokenType expectedType) {
        if (expectedType == currTokenType()) {
            advanceToken();
        }
        else {
            throwError();
        }
    }

    //   idList -> COMMA ID idList | lambda
    void idList(Predicate& predicate) {
        if (currTokenType() == COMMA) {
            match(COMMA);
            match(ID);
            predicate.addParameter(getPrevTokenContents());
            idList(predicate);
        }
        else {
            // lambda, do nothing
        }
    }

    //predicateList	->	COMMA predicate predicateList | lambda
    void predicateList(Predicate& predicate1) {
        if (currTokenType() == COMMA) {
            match(COMMA);
            predicate(predicate1);
            predicateList(predicate1);
        }
        else {
            // lambda, do nothing
        }
    }

    //predicateList	->	COMMA predicate predicateList | lambda
    void predicateListRule(Rule& rule1, Predicate& pred1) {
        if (currTokenType() == COMMA) {
            match(COMMA);
            predicateRule(rule1, pred1);
            predicateListRule(rule1, pred1);
        }
        else {
            // lambda, do nothing
        }
    }

    //parameterList	-> 	COMMA parameter parameterList | lambda
    void parameterList(Predicate& predicate) {
        if (currTokenType() == COMMA) {
            match(COMMA);
            parameter(predicate);
            parameterList(predicate);
        }
        else {
            // lambda, do nothing
        }
    }

    //parameterList	-> 	COMMA parameter parameterList | lambda
    void parameterListRule(Rule& newRule, Predicate& pred) {
        if (currTokenType() == COMMA) {
            match(COMMA);
            parameterRule(newRule, pred);
            parameterListRule(newRule, pred);
        }
        else {
            // lambda, do nothing
        }
    }

    //stringList	-> 	COMMA STRING stringList | lambda
    void stringList(Predicate& predicate) {
        if (currTokenType() == COMMA) {
            match(COMMA);
            match(STRING);
            program.addDomain(getPrevTokenContents());
            predicate.addParameter(getPrevTokenContents());
            stringList(predicate);
        }
        else {
            //lambda, do nothing
        }
    }

    //parameter	->	STRING | ID
    void parameter(Predicate& predicate) {
        if (currTokenType() == STRING) {
            match(STRING);
            predicate.addParameter(getPrevTokenContents());
        }
        else if (currTokenType() == ID) {
            match(ID);
            predicate.addParameter(getPrevTokenContents());
        }
        else {
            // lambda, do nothing
        }
    }

    //parameter	->	STRING | ID
    void parameterRule(Rule& newRule, Predicate& pred) {
        if (currTokenType() == STRING) {
            match(STRING);
            pred.addParameter(getPrevTokenContents());
        }
        else if (currTokenType() == ID) {
            match(ID);
            pred.addParameter(getPrevTokenContents());
        }
        else {
            // lambda, do nothing
        }
    }

    //headPredicate	->	ID LEFT_PAREN ID idList RIGHT_PAREN
    void headPredicate(Rule& newRule) {
        //Predicate head;
        match(ID);
        newRule.getHead().setName(getPrevTokenContents());
        match(LEFT_PAREN);
        match(ID);
        newRule.getHead().addParameter(getPrevTokenContents());
        idList(newRule.getHead());
        match(RIGHT_PAREN);
    }

    //predicate	->	ID LEFT_PAREN parameter parameterList RIGHT_PAREN
    void predicate(Predicate& predicate) {
        match(ID);
        predicate.setName(getPrevTokenContents());
        match(LEFT_PAREN);
        parameter(predicate);
        parameterList(predicate);
        match(RIGHT_PAREN);
    }

    //predicate	->	ID LEFT_PAREN parameter parameterList RIGHT_PAREN
    void predicateRule(Rule& newRule, Predicate& newPred) {
        match(ID);
        newPred.setName(getPrevTokenContents());
        match(LEFT_PAREN);
        parameterRule(newRule, newPred);
        parameterListRule(newRule, newPred);
        newRule.addPredicate(newPred);
        match(RIGHT_PAREN);
    }

    //scheme -> ID LEFT_PAREN ID idList RIGHT_PAREN
    void scheme() {
        Predicate newScheme;
        match(ID);
        newScheme.setName(getPrevTokenContents());
        match(LEFT_PAREN);
        match(ID);
        newScheme.addParameter(getPrevTokenContents());
        idList(newScheme);
        //what type should ID list return
        //how to get that from the ID list into newScheme
        //maybe give it the predicate
        //how do we make sure those updates are retained Predicate&
        //maybe use a member variable
        match(RIGHT_PAREN);
        program.addScheme(newScheme);
    }

    //fact -> ID LEFT_PAREN STRING stringList RIGHT_PAREN PERIOD
    void fact() {
        Predicate newFact;
        match(ID);
        newFact.setName(getPrevTokenContents());
        match(LEFT_PAREN);
        match(STRING);
        program.addDomain(getPrevTokenContents());
        newFact.addParameter(getPrevTokenContents());
        stringList(newFact);
        match(RIGHT_PAREN);
        match(PERIOD);
        program.addFact(newFact);
    }

    //rule -> headPredicate COLON_DASH predicate predicateList PERIOD
    void rule() {
        Rule newRule;
        Predicate newPred;
        headPredicate(newRule);
        match(COLON_DASH);
        predicateRule(newRule, newPred);
        predicateListRule(newRule, newPred);
        match(PERIOD);
        program.addRule(newRule);
    }

    //query	-> predicate Q_MARK
    void query() {
        Predicate newQuery;
        predicate(newQuery);
        match(Q_MARK);
        program.addQuery(newQuery);
    }

    //schemeList ->	scheme schemeList | lambda
    void schemeList() {
        if (currTokenType() == ID) {
            scheme();
            schemeList();
        }
        else {
            //lambda, do nothing
        }
    }

    //factList	->	fact factList | lambda
    void factList() {
        if (currTokenType() == ID) {
            fact();
            factList();
        }
        else {
            //lambda, do nothing
        }
    }

    //ruleList	->	rule ruleList | lambda
    void ruleList() {
        if (currTokenType() == ID) {
            rule();
            ruleList();
        }
        else {
            //lambda, do nothing
        }
    }

    //queryList	->	query queryList | lambda
    void queryList() {
        if (currTokenType() == ID) {
            query();
            queryList();
        }
        else {
            //lambda, do nothing
        }
    }
};

#endif //PROJECT1LEXER_PARSER_H
