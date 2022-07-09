#ifndef PROJECT1LEXER_PREDICATE_H
#define PROJECT1LEXER_PREDICATE_H
#include "Parameter.h"
#include <vector>
#include <sstream>

using namespace std;

class Predicate {
private:
    vector<Parameter> parameters;
    string name;

public:
    Predicate() {}

    // setters
    void setName(string newName) {
        name = newName;
    }

    void setParameters(vector<Parameter> newParameters) {
        parameters = newParameters;
    }

    // getters
    string getName() {
        return name;
    }

    vector<Parameter> getParameters() {
        return parameters;
    }

    // adder
    void addParameter(Parameter parameter) {
        parameters.push_back(parameter);
    }

    //helper function
    string addParameter(string parameterValue) {
        Parameter parameter;
        parameter.setValue(parameterValue);
        parameters.push_back(parameter);
    }

    // toString
    string toString() {
        string sep = "";
        stringstream out;
        out << name << "(";
        for (Parameter currParam : parameters) {
            out << sep << currParam.toString();
            sep = ",";
        }
        out << ")";
        return out.str();
    }
};

#endif //PROJECT1LEXER_PREDICATE_H
