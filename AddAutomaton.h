#ifndef PROJECT1LEXER_ADDAUTOMATON_H
#define PROJECT1LEXER_ADDAUTOMATON_H
#include "Automaton.h"

class AddAutomaton : public Automaton {
public:
    AddAutomaton() {
        type = TokenType::ADD; // set the type
    }

private:
    void s0() {
        if (match('+')) {
            next();
            return; // this represents accepting the input
        }
        else
            sError(); // this calls the error state
    }
};

#endif //PROJECT1LEXER_ADDAUTOMATON_H
