#ifndef PROJECT1LEXER_Q_MARKAUTOMATON_H
#define PROJECT1LEXER_Q_MARKAUTOMATON_H
#include "Automaton.h"

class Q_MarkAutomaton : public Automaton {
public:
    Q_MarkAutomaton() {
        type = TokenType::Q_MARK; // set the type
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

#endif //PROJECT1LEXER_Q_MARKAUTOMATON_H
