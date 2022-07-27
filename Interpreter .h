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

    void run() {
        evalSchemes();
        evalFacts();
        evalRules();
        evalQueries();
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
    }

    void evalFacts() {
        for (Predicate fact : program.getFacts()) {
            Tuple t;
            for (Parameter p : fact.getParameters()) {
                t.push_back(p.toString());
            }
            string factName = fact.getName();
            database.getRelation(factName)->addTuple(t);
        }
    }

    void evalRules() {
        cout << "Rule Evaluation" << endl;
        bool changed = true;
        unsigned int counter = 0;
        while (changed) {
            changed = false;
            for (Rule rule : program.getRules()) {
                Relation* result = nullptr;
                for (Predicate predicate : rule.getBody()) {
                    if (result == nullptr) {
                        result = evaluatePredicate(predicate);
                    }
                    else {
                        result = result->naturalJoin(evaluatePredicate(predicate));
                    }
                }
                Predicate p = rule.getHead();
                vector<string> relationHeader = result->getHeader().getAttributes();
                map<string, unsigned int> headerValues;
                unsigned int i = 0;
                for (i = 0; i < relationHeader.size(); ++i) {
                    headerValues[relationHeader.at(i)] = i;
                }
                vector<unsigned int> headerIndex;
                for (Parameter param : p.getParameters()) {
                    if (headerValues.find(param.getValue()) != headerValues.end()) {
                        unsigned int index = headerValues[param.getValue()];
                        headerIndex.push_back(index);
                    }
                }
                result = result->project(headerIndex);
                result = result->rename(database.getRelation(p.getName())->getHeader().getAttributes());
                result->setTuples(database.getRelation(p.getName())->newUnion(result));
                if (result->size() > 0) {
                    changed = true;
                }
                cout << rule.toString() << "." << endl;
                cout << result->toString();
            }
            counter++;
        }
        cout << endl << "Schemes populated after " << counter << " passes through the Rules." << endl << endl;
    }

    void evalQueries() {
        cout << "Query Evaluation" << endl;
        for (Predicate query : program.getQueries()) {
            Relation* result = evaluatePredicate(query);
            cout << query.toString() << "? ";
            if (result->size() > 0) {
                cout << "Yes(" << result->size() << ")" << endl;
            }
            else {
                cout << "No" << endl;
            }
            cout << result->toString();
        }
    }

    Relation* evaluatePredicate(Predicate predToEval) {
        // this function takes a relation from the database and selects, projects, and renames
        Relation* output = database.getRelation(predToEval.getName());
        map<string, unsigned int> parameterMap;
        vector<unsigned int> projectVector;
        vector<string> renameVector;
        unsigned int i = 0;
        for (Parameter p : predToEval.getParameters()) {
            if (p.isConst()) {
                // output select type 1 (int, value)
                output = output->select(i, p.toString());
            }
            else {
                if (!(parameterMap.find(p.toString()) == parameterMap.end())) {
                    // (int, int)
                    auto iterator = parameterMap.find(p.toString());
                    unsigned int val = iterator->second;
                    output = output->select(i,val);
                }
                else {
                    // mark it as seen
                    parameterMap.insert({p.toString(), i});
                    projectVector.push_back(i);
                    renameVector.push_back(p.toString());
                }
            }
            ++i;
        }
        output = output->project(projectVector);
        output = output->rename(renameVector);
        return output;
    }
};

#endif //PROJECT1LEXER_INTERPRETER_H
