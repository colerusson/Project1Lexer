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

    const string &getValue() const {
        return value;
    }

    void setValue(const string &value) {
        Parameter::value = value;
    }

    string toString() {
        return value;
    }
};

#endif //PROJECT1LEXER_PARAMETER_H
