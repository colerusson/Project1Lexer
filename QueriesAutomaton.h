#ifndef PROJECT1LEXER_QUERIESAUTOMATON_H
#define PROJECT1LEXER_QUERIESAUTOMATON_H
#include "Automaton.h"

class QueriesAutomaton : public Automaton {
public:
    QueriesAutomaton() {
        type = TokenType::QUERIES; // set the type
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

#endif //PROJECT1LEXER_QUERIESAUTOMATON_H
