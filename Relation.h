#ifndef PROJECT1LEXER_RELATION_H
#define PROJECT1LEXER_RELATION_H
#include <set>
#include "Tuple.h"

class Relation {
private:
    string name;
    Header header;
    set<Tuple> tuples;

public:
    Relation() {}

    const string &getName() const {
        return name;
    }

    void setName(const string &name) {
        Relation::name = name;
    }

    const Header &getHeader() const {
        return header;
    }

    void setHeader(const Header &header) {
        Relation::header = header;
    }

    const set <Tuple> &getTuples() const {
        return tuples;
    }

    void setTuples(const set <Tuple> &tuples) {
        Relation::tuples = tuples;
    }

    void addTuple(Tuple t) {
        tuples.insert(t);
    }

    unsigned int size() {
        return tuples.size();
    }

    string toString() {
        stringstream out;
        for (Tuple t : tuples) {
            if (t.size() > 0) {
                out << "  " << t.toString(header) << endl;
            }
        }
        return out.str();
    }

    Relation* select(unsigned int col, string expectedVal) {
        Relation* output = new Relation(); // make a new empty relation

        output->setName(this->name); // copy over name
        output->setHeader(this->header); // copy over header

        for (Tuple currTuple : this->tuples) { // loop through each tuple
            if (currTuple.at(col) == expectedVal) {
                output->addTuple(currTuple);
            }
        }
        return output;
    }

    Relation* select(unsigned int col1, unsigned int col2) {
        Relation *output = new Relation(); // make a new empty relation

        output->setName(this->name); // copy over name
        output->setHeader(this->header); // copy over header

        for (Tuple currTuple: this->tuples) { // loop through each tuple
            if (currTuple.at(col1) == currTuple.at(col2)) {
                output->addTuple(currTuple);
            }
        }
        return output;
    }

    Relation* rename(vector<string> newAttributes) {
        Relation* output = new Relation();
        output->setName(name);
        Header newHeader = Header(newAttributes);
        output->setHeader(newHeader);
        output->setTuples(tuples);
        return output;
    }

    Relation* project(vector<unsigned int> colsToKeep) {
        Relation* output = new Relation();
        output->setName(name);
        Header newHeader = Header();
        for (unsigned int i = 0; i < colsToKeep.size(); ++i) {
            newHeader.push_back(this->header.at(i));
        }
        output->setHeader(newHeader);
        output->setTuples(tuples);
        for (Tuple t : tuples) {
            Tuple newTuple = Tuple();
            for (unsigned int i = 0; i < colsToKeep.size(); ++i) {
                newTuple.push_back(t.at(i));
            }
            output->addTuple(newTuple);
        }
        return output;
    }
};

#endif //PROJECT1LEXER_RELATION_H
