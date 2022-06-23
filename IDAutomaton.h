#ifndef PROJECT1LEXER_IDAUTOMATON_H
#define PROJECT1LEXER_IDAUTOMATON_H
#include "Automaton.h"
#include <stdio.h>
#include <ctype.h>

class IDAutomaton : public Automaton {
public:
    IDAutomaton() {
        type = TokenType::ID; // set the type
    }
private:
    void s0() {
        if (isalpha(curr())) {
            next();
            s1();
        }
        else
            sError();
    }
    void s1() {
        if (endOfFile()) {
            return; // accept
        }
        else if (isalnum(curr())) {
            next();
            s1();
        }
        else
            return; //accept
    }
};

#endif //PROJECT1LEXER_IDAUTOMATON_H
