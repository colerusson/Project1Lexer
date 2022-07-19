#ifndef PROJECT1LEXER_HEADER_H
#define PROJECT1LEXER_HEADER_H
#include <vector>
#include <string>
using namespace std;

class Header {
private:
    vector<string> attributes;

public:
    Header() { }
    Header(vector<string> attributes) : attributes(attributes) {}

    const vector<string> &getAttributes() const {
        return attributes;
    }

    void setAttributes(const vector<string> &attributes) {
        Header::attributes = attributes;
    }

    // Header :
    unsigned int size() {
        return attributes.size();
    }

    string at(unsigned int index) {
        // for at methods
        if (index >= size()) {
            throw "ERROR";
        }
        return attributes.at(index);
    }

    void push_back(string value) {
        attributes.push_back(value);
    }
};

#endif //PROJECT1LEXER_HEADER_H
