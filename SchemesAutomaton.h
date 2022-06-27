#ifndef PROJECT1LEXER_SCHEMESAUTOMATON_H
#define PROJECT1LEXER_SCHEMESAUTOMATON_H
#include "Automaton.h"

class SchemesAutomaton : public Automaton {
public:
    SchemesAutomaton() {
        type = TokenType::SCHEMES; // set the type
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

#endif //PROJECT1LEXER_SCHEMESAUTOMATON_H
