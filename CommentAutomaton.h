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
            return;
        }
        else if (match('|')) {
            sError();
        }
        else {
            s2();
        }
    }

    void s2() {
        if (endOfFile()) {
            return;
        }
        else if (!match('\n')) {
            next();
            s2();
        }
        else {
            return;
        }
    }
};

#endif //PROJECT1LEXER_COMMENTAUTOMATON_H
