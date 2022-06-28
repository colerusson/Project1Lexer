#ifndef PROJECT1LEXER_BLOCKCOMMENTAUTOMATON_H
#define PROJECT1LEXER_BLOCKCOMMENTAUTOMATON_H
#include "Automaton.h"

class BlockCommentAutomaton : public Automaton {
public:
    BlockCommentAutomaton() {
        type = TokenType::BLOCK; // set the type
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
        if (match('|')) {
            next();
            s2();
        }
        else
            sError(); // this calls the error state
    }

    void s2() {
        if (!match('|')) {
            next();
            if (endOfFile()) {
                type = TokenType::UNDEFINED;
                return;
            }
            s2();
        }
        else {
            next();
            s3();
        }
    }

    void s3() {
        if (!match('#')) {
            next();
            s2();
        }
        else {
            next();
            return;
        }
    }
};

#endif //PROJECT1LEXER_BLOCKCOMMENTAUTOMATON_H
