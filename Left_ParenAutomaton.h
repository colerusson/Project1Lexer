#ifndef PROJECT1LEXER_LEFT_PARENAUTOMATON_H
#define PROJECT1LEXER_LEFT_PARENAUTOMATON_H
#include "Automaton.h"

class Left_ParenAutomaton : public Automaton {
public:
    Left_ParenAutomaton() {
        type = TokenType::LEFT_PAREN; // set the type
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

#endif //PROJECT1LEXER_LEFT_PARENAUTOMATON_H
