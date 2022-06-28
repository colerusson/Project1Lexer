#ifndef PROJECT1LEXER_COMMENTAUTOMATON_H
#define PROJECT1LEXER_COMMENTAUTOMATON_H
#include "Automaton.h"

class CommentAutomaton : public Automaton {
public:
    CommentAutomaton() {
        type = TokenType::COMMENT; // set the type
    }

private:
    void s0() {
        if (match('#')) {
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
        else if (!match('\n')) {
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
        if (endOfFile()) {
            sError();
        }
        else if (getNewLines() > 0) {
            return;
        }
        else {
            next();
            s2();
        }
    }
};

#endif //PROJECT1LEXER_COMMENTAUTOMATON_H
