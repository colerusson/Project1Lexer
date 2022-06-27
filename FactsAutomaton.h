#ifndef PROJECT1LEXER_FACTSAUTOMATON_H
#define PROJECT1LEXER_FACTSAUTOMATON_H
#include "Automaton.h"

class FactsAutomaton : public Automaton {
public:
    FactsAutomaton() {
        type = TokenType::FACTS; // set the type
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

#endif //PROJECT1LEXER_FACTSAUTOMATON_H
