#ifndef PROJECT1LEXER_PARAMETER_H
#define PROJECT1LEXER_PARAMETER_H
#include <string>
#include <ostream>

using namespace std;

class Parameter {
private:
    string value;

public:
    Parameter() {}
    Parameter(const string &value) : value(value) {}

    const string &getValue() const {
        return value;
    }

    void setValue(const string &value) {
        Parameter::value = value;
    }

    bool isConst() {
        bool isConst;
        if (value.at(0) == '\'') {
            isConst = true;
        }
        else {
            isConst = false;
        }
        return isConst;
    }

    string toString() {
        return value;
    }
};

#endif //PROJECT1LEXER_PARAMETER_H
