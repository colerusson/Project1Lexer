#ifndef PROJECT1LEXER_RULESAUTOMATON_H
#define PROJECT1LEXER_RULESAUTOMATON_H
#include "Automaton.h"

class RulesAutomaton : public Automaton {
public:
    RulesAutomaton() {
        type = TokenType::RULES; // set the type
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

#endif //PROJECT1LEXER_RULESAUTOMATON_H
