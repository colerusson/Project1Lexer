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
        //scheme();
        //fact();
        //rule();
        //query();
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
    void idList() {
        if (currTokenType() == COMMA) {
            match(COMMA);
            match(ID);
            idList();
        }
        else {
            // lambda, do nothing
        }
    }

    //predicateList	->	COMMA predicate predicateList | lambda
    void predicateList() {
        if (currTokenType() == COMMA) {
            match(COMMA);
            predicate();
            predicateList();
        }
        else {
            // lambda, do nothing
        }
    }

    //parameterList	-> 	COMMA parameter parameterList | lambda
    void parameterList() {
        if (currTokenType() == COMMA) {
            match(COMMA);
            parameter();
            parameterList();
        }
        else {
            // lambda, do nothing
        }
    }

    //stringList	-> 	COMMA STRING stringList | lambda
    void stringList() {
        if (currTokenType() == COMMA) {
            match(COMMA);
            match(STRING);
            stringList();
        }
        else {
            //lambda, do nothing
        }
    }

    //parameter	->	STRING | ID
    void parameter() {
        if (currTokenType() == STRING) {
            match(STRING);
        }
        else if (currTokenType() == ID) {
            match(ID);
        }
        else {
            // lambda, do nothing
        }
    }

    //headPredicate	->	ID LEFT_PAREN ID idList RIGHT_PAREN
    void headPredicate() {
        match(ID);
        match(LEFT_PAREN);
        match(ID);
        idList();
        match(RIGHT_PAREN);
    }

    //predicate	->	ID LEFT_PAREN parameter parameterList RIGHT_PAREN
    void predicate() {
        match(ID);
        match(LEFT_PAREN);
        parameter();
        parameterList();
        match(RIGHT_PAREN);
    }

    //scheme -> ID LEFT_PAREN ID idList RIGHT_PAREN
    void scheme() {
        Predicate newScheme;
        match(ID);
        newScheme.setName(getPrevTokenContents());
        match(LEFT_PAREN);
        match(ID);
        Parameter firstParameter;
        firstParameter.setValue(getPrevTokenContents());
        newScheme.addParameter(firstParameter);
        idList();
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
        match(ID);
        match(LEFT_PAREN);
        match(STRING);
        stringList();
        match(RIGHT_PAREN);
        match(PERIOD);
    }

    //rule -> headPredicate COLON_DASH predicate predicateList PERIOD
    void rule() {
        headPredicate();
        match(COLON_DASH);
        predicate();
        predicateList();
        match(PERIOD);
    }

    //query	-> predicate Q_MARK
    void query() {
        predicate();
        match(Q_MARK);
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
