#ifndef PROJECT1LEXER_COLONAUTOMATON_H
#define PROJECT1LEXER_COLONAUTOMATON_H
#include "Automaton.h"

class ColonAutomaton : public Automaton {
public:
    ColonAutomaton() {
        type = TokenType::COLON; // set the type
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

#endif //PROJECT1LEXER_COLONAUTOMATON_H
