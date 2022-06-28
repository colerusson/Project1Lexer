#ifndef PROJECT1LEXER_PERIODAUTOMATON_H
#define PROJECT1LEXER_PERIODAUTOMATON_H
#include "Automaton.h"

class PeriodAutomaton : public Automaton {
public:
    PeriodAutomaton() {
        type = TokenType::PERIOD; // set the type
    }

private:
    void s0() {
        if (match('.')) {
            next();
            return; // this represents accepting the input
        }
        else
            sError(); // this calls the error state
    }
};

#endif //PROJECT1LEXER_PERIODAUTOMATON_H
