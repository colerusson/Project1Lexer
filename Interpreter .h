#ifndef PROJECT1LEXER_INTERPRETER_H
#define PROJECT1LEXER_INTERPRETER_H
#include "DatalogProgram.h"
#include "Database.h"
#include "Graph.h"

class Interpreter {
private:
    DatalogProgram program;
    Database database;
    Graph graph;
    set<unsigned int> dependencies;
    set<unsigned int> reverseDependencies;

public:
    Interpreter() {}
    Interpreter(const DatalogProgram &program) : program(program) {}

    void run() {
        evalSchemes();
        evalFacts();
        createGraph();
        createReverseGraph();
        postOrder();
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

    void createGraph() {
        unsigned int i = 0;
        for (Rule rule : program.getRules()) {
            for (Predicate predicate : rule.getBody()) {
                unsigned int j = 0;
                for (Rule rule2 : program.getRules()) {
                    if (rule2.getHead().getName() == predicate.getName()) {
                        dependencies.insert(j);
                    }
                    ++j;
                }
            }
            graph.addToGraph(i, dependencies);
            dependencies.clear();
            ++i;
        }
        cout << "Dependency Graph" << endl;
        cout << graph.toString() << endl;
    }

    void createReverseGraph() {
        unsigned int i = 0;
        for (Rule rule : program.getRules()) {
            unsigned int j = 0;
            for (Rule rule2 : program.getRules()) {
                for (Predicate predicate : rule2.getBody()) {
                    if (rule.getHead().getName() == predicate.getName()) {
                        reverseDependencies.insert(j);
                    }
                }
                ++j;
            }
            graph.addToReverseGraph(i, reverseDependencies);
            reverseDependencies.clear();
            ++i;
        }
    }

    void postOrder() {
        graph.dfsReverse();
        graph.dfs();
    }

    void evalRules() {
        cout << "Rule Evaluation" << endl;
        vector<set<int>> sCCs = graph.getScCs();
        for (unsigned int i = 0; i < sCCs.size(); i++) {
            cout << "SCC: ";
            bool firstItem = true;
            for (int rVal : sCCs[i]) {
                if (!firstItem) {
                    cout << ",";
                }
                firstItem = false;
                cout << "R" << rVal;
            }
            cout << endl;
            bool changed = true;
            unsigned int counter = 0;
            vector<Rule> rules = program.getRules();
            while (changed) {
                changed = false;
                counter++;
                for (unsigned int j : sCCs[i]) {
                    Relation *result = nullptr;
                    for (Predicate predicate: rules[j].getBody()) {
                        if (result == nullptr) {
                            result = evaluatePredicate(predicate);
                        } else {
                            result = result->naturalJoin(evaluatePredicate(predicate));
                        }
                    }
                    Predicate p = rules[j].getHead();
                    vector<string> relationHeader = result->getHeader().getAttributes();
                    map<string, unsigned int> headerValues;
                    for (unsigned int k = 0; k < relationHeader.size(); ++k) {
                        headerValues[relationHeader.at(k)] = k;
                    }
                    vector<unsigned int> headerIndex;
                    for (Parameter param: p.getParameters()) {
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
                    cout << rules[j].toString() << "." << endl;
                    cout << result->toString();
                }
            }
            cout << counter << " passes: ";
            string sep = "";
            for (unsigned int k : sCCs[i]) {
                cout << sep << "R" << k;
                sep = ",";
            }
            cout << endl;
        }
    }

    void evalQueries() {
        cout << endl << "Query Evaluation" << endl;
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
