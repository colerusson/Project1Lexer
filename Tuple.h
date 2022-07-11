#ifndef PROJECT1LEXER_TUPLE_H
#define PROJECT1LEXER_TUPLE_H
#include "Header.h"
#include <set>

class Tuple {
private:
    vector<string> values;

public:
    Tuple() { }
    Tuple(vector<string> values) : values(values) { }

    const vector<string> &getValues() const {
        return values;
    }

    void setValues(const vector<string> &values) {
        Tuple::values = values;
    }

    //You must define this to allow tuples to be put into a set
    bool operator<(const Tuple t) const {
        return values < t.values;
    }

    // TODO: add more delegation functions as needed

};


#endif //PROJECT1LEXER_TUPLE_H
