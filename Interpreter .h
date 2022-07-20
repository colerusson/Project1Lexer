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
    //it evaluates all the relations

    void run() {
        // evalSchemes       //all relations are essentially schemes and facts
        // evalFacts
        // evalRules        //this will be project 4
        // evalQueries      //uses the relations to evaluate

        //evaluating the schemes facts and rules makes the database
        //the queries evaluates what is in the database
    }

    void evalSchemes() {
        for (Predicate scheme : program.getSchemes()) {
            Relation* schemesRel = new Relation;
            Header header;
            for (Parameter p : scheme.getParameters()) {
                header.push_back(p.toString());
            }
            string schemeName = scheme.getName();
            schemesRel->setName(schemeName);
            schemesRel->setHeader(header);
            database.addRelation(schemeName, schemesRel);
        }
        //add stuff to the database here
        //takes all the data and makes a relation object that we can pass to database
        //take your schemes, make a new relation object for each one, get name and set name
        //get all the parameters and put in the header
        //and then put that relation and put it in the database
        //make a for loop and make a new relation each time
        //put a breakpoint at the beginning hear and walk through to see what is being added
    }

    void evalFacts() {
        for (Predicate fact : program.getFacts()) {
            string factName = fact.getName();

        }
        //add stuff to the database here - make a tuple for each fact and add it to the respective relation
        //here we don't make new relations, we just add to the relations that are already made in schemes
        //use search and stuff for the facts to find matching scheme relation object
        //here we can cout things to see the tuples
    }

    void evalRules() {
        //add stuff to the database here
    }

    void evalQueries() {
        //here we will evaluate the queries and then print them out for the output
        for (Predicate query : program.getQueries()) {
            Relation* result = evaluatePredicate(query);
        }

        //this is where we use the project and rename and such just one time
    }

    Relation* evaluatePredicate(Predicate predToEval) {
        //this function takes a relation from the databse and selects, projects, and renames
        Relation* output = database.getRelation(predToEval.getName());
        for (Parameter p : predToEval.getParameters()) {
            if (p.isConst()) {
                //constant means it is a string, within single quotes
                //variable means that it is an ID value, not in quotes
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
        //rename
        return output;
    }
};

#endif //PROJECT1LEXER_INTERPRETER_H
