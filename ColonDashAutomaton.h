#ifndef PROJECT1LEXER_COLONDASHAUTOMATON_H
#define PROJECT1LEXER_COLONDASHAUTOMATON_H
#include "Automaton.h"

class ColonDashAutomaton : public Automaton {
public:
    ColonDashAutomaton() {
        type = TokenType::COLON_DASH; // set the type
    }
private:
    void s0() {
        if (match(':')) {
            next();
            s1(); // call s1 as the transition
        }
        else
            sError(); // this calls the error state
    }
    void s1() {
        if (endOfFile()) {
            sError();
        }
        else if (match('-')) {
            next();
            return; // this represents accepting the input
        }
        else
            sError(); // this calls the error state
    }
};

#endif //PROJECT1LEXER_COLONDASHAUTOMATON_H
