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
        if (match('R')) {
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
        else if (match('u')) {
            next();
            s2(); // call s2 as the transition
        }
        else
            sError(); // this calls the error state
    }

    void s2() {
        if (endOfFile()) {
            sError();
        }
        else if (match('l')) {
            next();
            s3(); // call s3 as the transition
        }
        else
            sError(); // this calls the error state
    }

    void s3() {
        if (endOfFile()) {
            sError();
        }
        else if (match('e')) {
            next();
            s4(); // call s4 as the transition
        }
        else
            sError(); // this calls the error state
    }

    void s4() {
        if (endOfFile()) {
            sError();
        }
        else if (match('s')) {
            next();
            return; // this represents accepting the input
        }
        else
            sError(); // this calls the error state
    }
};

#endif //PROJECT1LEXER_RULESAUTOMATON_H
