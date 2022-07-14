#ifndef PROJECT1LEXER_RELATION_H
#define PROJECT1LEXER_RELATION_H
#include <set>
#include <map>
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
                out << t.toString(header) << endl;
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
        //{3,2}
        //set name to something
        //create a new header (empty)
            //fill that header with the reordered data
            //(A, B, C, D, E) -> (D, C)
            //Put that header into the output relation

        //for each tuple t
            //new empty tuple
                //fill that tuple with reordered data
                //(1, 2, 3, 4, 5) -> (4, 3)
            //put that tuple into the output relation
    }
};

#endif //PROJECT1LEXER_RELATION_H
