#ifndef PROJECT1LEXER_MULTIPLYAUTOMATON_H
#define PROJECT1LEXER_MULTIPLYAUTOMATON_H
#include "Automaton.h"

class MultiplyAutomaton : public Automaton {
public:
    MultiplyAutomaton() {
        type = TokenType::MULTIPLY; // set the type
    }

private:
    void s0() {
        if (match('*')) {
            next();
            return; // this represents accepting the input
        }
        else
            sError(); // this calls the error state
    }
};

#endif //PROJECT1LEXER_MULTIPLYAUTOMATON_H
