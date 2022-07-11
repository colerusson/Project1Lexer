#ifndef PROJECT1LEXER_RULE_H
#define PROJECT1LEXER_RULE_H
#include "Predicate.h"

class Rule {
private:
    Predicate head;
    vector<Predicate> body;

public:
    Rule() {}

    Predicate &getHead()  {
        return head;
    }

    void setHead(const Predicate &head) {
        Rule::head = head;
    }

    const vector<Predicate> &getBody() const {
        return body;
    }

    void setBody(const vector<Predicate> &body) {
        Rule::body = body;
    }

    //adder function
    void addPredicate(Predicate predicateValue) {
        body.push_back(predicateValue);
    }

    string toString() {
        string sep = "";
        stringstream out;
        out << head.toString() << " :- ";
        for (Predicate currPred : body) {
            out << sep << currPred.toString();
            sep = ",";
        }
        return out.str();
    }
};

#endif //PROJECT1LEXER_RULE_H
