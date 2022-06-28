#ifndef PROJECT1LEXER_LEXER_H
#define PROJECT1LEXER_LEXER_H
#include <vector>
#include <cctype>
#include <iostream>
#include <algorithm>
#include "Token.h"
#include "Automaton.h"
#include "IDAutomaton.h"
#include "AddAutomaton.h"
#include "FactsAutomaton.h"
#include "ColonAutomaton.h"
#include "CommaAutomaton.h"
#include "RulesAutomaton.h"
#include "PeriodAutomaton.h"
#include "Q_MarkAutomaton.h"
#include "StringAutomaton.h"
#include "QueriesAutomaton.h"
#include "SchemesAutomaton.h"
#include "CommentAutomaton.h"
#include "MultiplyAutomaton.h"
#include "ColonDashAutomaton.h"
#include "Left_ParenAutomaton.h"
#include "Right_ParenAutomaton.h"
#include "BlockCommentAutomaton.h"
#include "UndefinedCharAutomaton.h"

class Lexer {
private:
    vector<Token> tokens;
    vector<Automaton*> automata;

public:
    void initializeAutomata() {
        automata.push_back(new ColonAutomaton());
        automata.push_back(new ColonDashAutomaton());
        automata.push_back(new FactsAutomaton());
        automata.push_back(new RulesAutomaton());
        automata.push_back(new QueriesAutomaton());
        automata.push_back(new SchemesAutomaton());
        automata.push_back(new AddAutomaton());
        automata.push_back(new MultiplyAutomaton());
        automata.push_back(new CommaAutomaton());
        automata.push_back(new StringAutomaton());
        automata.push_back(new Right_ParenAutomaton());
        automata.push_back(new Left_ParenAutomaton());
        automata.push_back(new Q_MarkAutomaton());
        automata.push_back(new PeriodAutomaton());
        automata.push_back(new IDAutomaton());
        automata.push_back(new CommentAutomaton());
        automata.push_back(new BlockCommentAutomaton());
        automata.push_back(new UndefinedCharAutomaton());
    }

    vector<Token> run(string input) {
        unsigned int line = 1;
        initializeAutomata();
        while (input.size() > 0) {
            Automaton *maxAutomaton = automata.at(0);
            unsigned int maxRead = 0;
            while (isspace(input[0]) || input[0] == '\n') {
                if (input[0] == '\n') {
                    line += 1;
                }
                input = input.substr(1);
            }
            for (unsigned int i = 0; i < automata.size(); i++) {
                Automaton *currAutomaton = automata.at(i);
                unsigned int numCharRead = currAutomaton->run(input);
                if (numCharRead > maxRead) {
                    maxRead = numCharRead;
                    maxAutomaton = currAutomaton;
                }
            }
            Token currToken = Token(maxAutomaton->getType(), input.substr(0, maxRead), line);
            if (currToken.getType() == "COMMENT") {
                currToken = Token(maxAutomaton->getType(), input.substr(0, maxRead - 1), line);
            }
            cout << currToken.toString() << endl;
            input = input.substr(maxRead);
            line += maxAutomaton->getNewLines();
            tokens.push_back(currToken);
        }
        Token t = Token(END_OF_FILE, "", line);
        tokens.push_back(t);
        cout << t.toString() << endl;
        return tokens;
    }
};

#endif //PROJECT1LEXER_LEXER_H
