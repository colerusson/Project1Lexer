#ifndef PROJECT1LEXER_STRINGAUTOMATON_H
#define PROJECT1LEXER_STRINGAUTOMATON_H
#include "Automaton.h"

class StringAutomaton : public Automaton {
public:
    StringAutomaton() {
        type = TokenType::STRING; // set the type
    }

private:
    void s0() {
        if (match('\'')) {
            next();
            s1(); // call s1 as the transition
        }
        else
            sError(); // this calls the error state
    }

    void s1() {
        if (!match('\'')) {
            next();
            if (endOfFile()) {
                type = TokenType::UNDEFINED;
                return;
            }
            s1();
        }
        else {
            next();
            s2();
        }
    }

    void s2() {
        if (match('\'')) {
            next();
            s1();
        }
        else {
            next();
            return;
        }
    }
};

#endif //PROJECT1LEXER_STRINGAUTOMATON_H
