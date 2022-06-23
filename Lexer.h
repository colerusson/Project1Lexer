#ifndef PROJECT1LEXER_LEXER_H
#define PROJECT1LEXER_LEXER_H
#include <vector>
#include <iostream>
#include "Token.h"
#include "Automaton.h"
#include "IDAutomaton.h"
#include "ColonAutomaton.h"
#include "ColonDashAutomaton.h"
#include "UndefinedCharAutomaton.h"

class Lexer {
private:
    vector<Token> tokens;
    vector<Automaton*> automata;

public:
    void initializeAutomata() {
        automata.push_back(new ColonAutomaton());
        automata.push_back(new ColonDashAutomaton());
        automata.push_back(new IDAutomaton());
        automata.push_back(new UndefinedCharAutomaton());
    }

    vector<Token> run(string input) {
        initializeAutomata();
        while (input.size() > 0) {
            Automaton *maxAutomaton = automata.at(0);
            unsigned int maxRead = 0;
            // TODO handle whitespace
            for (unsigned int i = 0; i < automata.size(); i++) {
                Automaton *currAutomaton = automata.at(i);
                unsigned int numCharRead = currAutomaton->run(input);
                if (numCharRead > maxRead) {
                    maxRead = numCharRead;
                    maxAutomaton = currAutomaton;
                }
            }
            Token currToken = Token(maxAutomaton->getType(), input.substr(0, maxRead), 0);
            cout << currToken.toString() << endl;
            input = input.substr(maxRead);
            tokens.push_back(currToken);
        }
        return tokens;
    }
};

#endif //PROJECT1LEXER_LEXER_H
