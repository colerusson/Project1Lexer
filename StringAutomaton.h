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
        if (match(':')) {
            next();
            return; // this represents accepting the input
        }
        else
            sError(); // this calls the error state
    }
};

#endif //PROJECT1LEXER_STRINGAUTOMATON_H
