#ifndef PROJECT1LEXER_COMMAAUTOMATON_H
#define PROJECT1LEXER_COMMAAUTOMATON_H
#include "Automaton.h"

class CommaAutomaton : public Automaton {
public:
    CommaAutomaton() {
        type = TokenType::COMMA; // set the type
    }

private:
    void s0() {
        if (match(':')) {
            next();
            return; // this represents accepting the input
        }
        else
            sError(); // this calls the error state
    }
};

#endif //PROJECT1LEXER_COMMAAUTOMATON_H
