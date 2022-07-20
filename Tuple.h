#ifndef PROJECT1LEXER_TUPLE_H
#define PROJECT1LEXER_TUPLE_H
#include "Header.h"
#include <sstream>

class Tuple {
private:
    vector<string> values;

public:
    Tuple() { }
    Tuple(vector<string> values) : values(values) {}

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

    // Tuple :
    unsigned int size() {
        return values.size();
    }

    string at(unsigned int index) {
        // for at methods
        if (index >= size()) {
            throw "ERROR (1)";
        }
        return values.at(index);
    }

    void push_back(string value) {
        values.push_back(value);
    }

    // This goes in your tuple class, note that tuple must include Header.h
    string toString(Header header) {
        // for the toString
        if (size() != header.size()) {
            cout << size() << endl << header.size() << endl;
            throw "ERROR (2)";
        }
        stringstream out;
        string sep = "";
        for (unsigned i = 0; i < size(); i++) {
            string name = header.at(i);
            string value = at(i);
            out << sep << name << "=" << value;
            sep = ", ";
        }
        return out.str();
    }
};

#endif //PROJECT1LEXER_TUPLE_H
