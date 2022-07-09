#ifndef PROJECT1LEXER_DATALOGPROGRAM_H
#define PROJECT1LEXER_DATALOGPROGRAM_H
#include "Predicate.h"
#include "Rule.h"
#include <set>

class DatalogProgram {
private:
    vector<Predicate> schemes;
    vector<Predicate> facts;
    vector<Rule> rules;
    vector<Predicate> queries;
    set<string> domain;

public:
    DatalogProgram() {}

    const vector<Predicate> &getSchemes() const {
        return schemes;
    }

    void setSchemes(const vector<Predicate> &schemes) {
        DatalogProgram::schemes = schemes;
    }

    const vector<Predicate> &getFacts() const {
        return facts;
    }

    void setFacts(const vector<Predicate> &facts) {
        DatalogProgram::facts = facts;
    }

    const vector<Rule> &getRules() const {
        return rules;
    }

    void setRules(const vector<Rule> &rules) {
        DatalogProgram::rules = rules;
    }

    const vector<Predicate> &getQueries() const {
        return queries;
    }

    void setQueries(const vector<Predicate> &queries) {
        DatalogProgram::queries = queries;
    }

    const set<string> &getDomain() const {
        return domain;
    }

    void setDomain(const set<string> &domain) {
        DatalogProgram::domain = domain;
    }

    // adder
    void addScheme(Predicate scheme) {
        schemes.push_back(scheme);
    }

    // adder
    void addFact(Predicate fact) {
        facts.push_back(fact);
    }

    // adder
    void addQuery(Predicate query) {
        queries.push_back(query);
    }

    // adder
    void addRule(Rule rule) {
        rules.push_back(rule);
    }

    //adder
    void addDomain(string value) {
        domain.insert(value);
    }

    string toString() {
        stringstream out;
        out << "Schemes(" << schemes.size() << "):" << endl;
        for (Predicate currPred : schemes) {
            out << "  " << currPred.toString() << endl;
        }
        out << "Facts(" << facts.size() << "):" << endl;
        for (Predicate currPred : facts) {
            out << "  " << currPred.toString() << "." << endl;
        }
        out << "Rules(" << rules.size() << "):" << endl;
        for (Rule currRule : rules) {
            out << "  " << currRule.toString() << "." << endl;
        }
        out << "Queries(" << queries.size() << "):" << endl;
        for (Predicate currPred : queries) {
            out << "  " << currPred.toString() << "?" << endl;
        }
        out << "Domain(" << domain.size() << "):" << endl;
        for (string currVal : domain) {
            out << "  " << currVal << endl;
        }
        return out.str();
    }
};

#endif //PROJECT1LEXER_DATALOGPROGRAM_H
