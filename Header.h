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
    Header(vector<string> attributes) : attributes(attributes) { }

    const vector<string> &getAttributes() const {
        return attributes;
    }

    void setAttributes(const vector<string> &attributes) {
        Header::attributes = attributes;
    }
};


#endif //PROJECT1LEXER_HEADER_H
