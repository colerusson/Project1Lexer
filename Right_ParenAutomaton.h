#ifndef PROJECT1LEXER_RIGHT_PARENAUTOMATON_H
#define PROJECT1LEXER_RIGHT_PARENAUTOMATON_H
#include "Automaton.h"

class Right_ParenAutomaton : public Automaton {
public:
    Right_ParenAutomaton() {
        type = TokenType::RIGHT_PAREN; // set the type
    }

private:
    void s0() {
        if (match(')')) {
            next();
            return; // this represents accepting the input
        }
        else
            sError(); // this calls the error state
    }
};

#endif //PROJECT1LEXER_RIGHT_PARENAUTOMATON_H
