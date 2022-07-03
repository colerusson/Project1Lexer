#ifndef PROJECT1LEXER_PARSER_H
#define PROJECT1LEXER_PARSER_H
#include <vector>
#include "Token.h"
#include <iostream>

class Parser {
private:
    vector<Token> tokens;
    unsigned int currTokenIndex = 0;

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

    void run() {
        DataLog();
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
        cout << "Token at index " << currTokenIndex << " was type: " << typeName(currTokenType()) << " expected: " << typeName(expectedType) << endl;
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
        if (currTokenIndex == COMMA) {
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
        if (currTokenIndex == COMMA) {
            match(COMMA);
            parameter();
            parameterList();
        }
        else {
            //lambda, do nothing
        }
    }

    //stringList	-> 	COMMA STRING stringList | lambda
    void stringList() {
        if (currTokenIndex == COMMA) {
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
        if (currTokenIndex == STRING) {
            match(STRING);
        }
        else if (currTokenIndex == ID) {
            match(ID);
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
        match(ID);
        match(LEFT_PAREN);
        match(ID);
        idList();
        match(RIGHT_PAREN);
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
