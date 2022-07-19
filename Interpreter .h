#ifndef PROJECT1LEXER_INTERPRETER_H
#define PROJECT1LEXER_INTERPRETER_H
#include "DatalogProgram.h"
#include "Database.h"

class Interpreter {
private:
    DatalogProgram program;
    Database database;

public:
    Interpreter() {}
    Interpreter(const DatalogProgram &program) : program(program) {}

    //the interpreter takes in the vectors from the datalog program to read and add to the database
    //it evaluates all of the relations

    void run() {
        // evalSchemes       //all relations are essentially schemes and facts
        // evalFacts
        // evalRules        //this will be project 4
        // evalQueries      //uses the relations to evaluate

        //evaluating the schemes facts and rules makes the database
        //the queries evaluates what is in the database
    }

    void evalSchemes() {
        //add stuff to the database here
    }

    void evalFacts() {
        //add stuff to the database here
    }

    void evalRules() {
        //add stuff to the database here
    }

    void evalQueries() {
        //here we will evaluate the queries and then print them out for the output
        for (Predicate query : program.getQueries()) {
            Relation* result = evaluatePredicate(query);
        }
    }

    Relation* evaluatePredicate(Predicate predToEval) {
        //this function takes a relation from the databse and selects, projects, and renames
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
