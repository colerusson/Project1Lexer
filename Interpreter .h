#ifndef PROJECT1LEXER_INTERPRETER_H
#define PROJECT1LEXER_INTERPRETER_H
#include "DatalogProgram.h"
#include "Relation.h"

class Interpreter {
private:
    DatalogProgram program;

public:
    Interpreter(DatalogProgram program)  : program(program)  {}

    void run() {
        // evalSchemes
        // evalFacts
        // evalRules
        // evalQueries
    }

    void evalSchemes() {

    }

    void evalFacts() {

    }

    void evalRules() {

    }

    void evalQueries() {
        for (Predicate query : program.getQueries()) {
            Relation* result = evaluatePredicate(query);
        }
    }

    Relation* evaluatePredicate(Predicate predToEval) {
        Relation* output = database.getRelation(predToEval.getName());
        for (Parameter p : predToEval.getParameters()) {
            if (p.isConst()) {
                // output select type 1 (int, value)
                output = output->select();
            }
            else {
                if (seenBefore()) {
                    // (int, int)
                    output = output->select();
                }
                else {
                    // mark it as seen
                }
            }
        }
        // project
        // rename
        return output;
    }
};

#endif //PROJECT1LEXER_INTERPRETER_H
