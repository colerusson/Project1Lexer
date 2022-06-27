#ifndef PROJECT1LEXER_TOKEN_H
#define PROJECT1LEXER_TOKEN_H
#include <string>
#include <sstream>
using namespace std;

enum TokenType {
    ADD, BLOCK, COMMA, COMMENT, COLON, COLON_DASH, UNDEFINED, ID, FACTS, LEFT_PAREN, RIGHT_PAREN,
    MULTIPLY, PERIOD, Q_MARK, QUERIES, RULES, SCHEMES, STRING
};

class Token {
private:
    TokenType type = UNDEFINED;
    string contents = "";
    unsigned int line = 0;

public:
    Token(TokenType type, const string &contents, unsigned int line) : type(type), contents(contents), line(line) {}

    string toString() const {
        stringstream out;
        out << "(" << typeName(type) << "," << "\"" << contents << "\"" << "," << line << ")";
        return out.str();
    }

    string typeName(TokenType type) const {
        switch (type) {
            case COMMA:
                return "COMMA";
            case COLON:
                return "COLON";
            case COLON_DASH:
                return "COLON_DASH";
            case ID:
                return "ID";
            case COMMENT:
                return "COMMENT";
            case BLOCK:
                return "COMMENT";
            case ADD:
                return "ADD";
            case FACTS:
                return "FACTS";
            case LEFT_PAREN:
                return "LEFT_PAREN";
            case RIGHT_PAREN:
                return "RIGHT_PAREN";
            case MULTIPLY:
                return "MULTIPLY";
            case PERIOD:
                return "PERIOD";
            case Q_MARK:
                return "Q_MARK";
            case QUERIES:
                return "QUERIES";
            case RULES:
                return "RULES";
            case SCHEMES:
                return "SCHEMES";
            case STRING:
                return "STRING";
            case UNDEFINED:
                return "UNDEFINED";
            default:
                return "ADD TO SWITCH";
        }
    }
};

#endif //PROJECT1LEXER_TOKEN_H
