#ifndef PROJECT1LEXER_TOKEN_H
#define PROJECT1LEXER_TOKEN_H
#include <string>
#include <sstream>
using namespace std;

enum TokenType {
    COMMA, COLON, COLON_DASH, UNDEFINED, ID // add more here
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
            case UNDEFINED:
                return "UNDEFINED";
            default:
                return "ADD TO SWITCH";
        }
    }
};

#endif //PROJECT1LEXER_TOKEN_H
