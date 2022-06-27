#ifndef PROJECT1LEXER_UNDEFINEDCHARAUTOMATON_H
#define PROJECT1LEXER_UNDEFINEDCHARAUTOMATON_H
#include "Automaton.h"

class UndefinedCharAutomaton : public Automaton {
public:
    UndefinedCharAutomaton() {
        type = TokenType::UNDEFINED; // set the type
    }

private:
    void s0() {
        next(); // read next character
        return; // accept the input
    }
};

#endif //PROJECT1LEXER_UNDEFINEDCHARAUTOMATON_H
