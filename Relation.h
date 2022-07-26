#ifndef PROJECT1LEXER_RELATION_H
#define PROJECT1LEXER_RELATION_H
#include <set>
#include <map>
#include <utility>
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
        Header newHeader;
        for (unsigned int column : colsToKeep) {
            newHeader.push_back(header.at(column));
        }
        output->setHeader(newHeader);
        for (Tuple t : tuples) {
            Tuple newTuple;
            for (unsigned int column : colsToKeep) {
                newTuple.push_back(t.at(column));
            }
            output->addTuple(newTuple);
        }
        return output;
    }

    Relation* naturalJoin(Relation* other) {
        Relation* r1 = this;
        Relation* r2 = other;
        Relation* output = new Relation();
        // set name of output relation
        output->setName(r1->getName() + " |x| " + r2->getName());
        unsigned int index1;
        unsigned int index2;
        bool found;
        Header h1 = r1->getHeader();
        Header h2 = r2->getHeader();
        // initialize overlap object here
        vector<pair<unsigned int, unsigned int>> overlap;
        // initialize unique columns object
        vector<unsigned int> uniqueCols;
        // calculate header overlap of 'this' and 'other' relations
        for (index2 = 0; index2 < h2.size(); ++index2) {
            found = false;
            for (index1 = 0; index1 < h1.size(); ++index1) {
                if (h1.at(index1) == h2.at(index2)) {
                    found = true;
                    overlap.push_back({index1, index2});
                }
            }
            if (!found) {
                uniqueCols.push_back(index2);
            }
        }
        // combine headers -- will be the header for 'output'
        output->setHeader(combineHeaders(h1, h2, uniqueCols));
        // combine tuples -- will be the tuples for 'output'
        for (Tuple t1 : r1->getTuples()) {
            for (Tuple t2 : r2->getTuples()) {
                if (isJoinable(t1, t2, overlap)) {
                    Tuple newTuple = combineTuples(t1, t2, uniqueCols);
                    output->addTuple(newTuple);
                }
            }
        }
        return output;
    }

    Header combineHeaders(Header& h1, Header& h2, vector<unsigned int> uniqueCols) {
        // let newHeader be a new empty header
        Header newHeader;
        // copy all values from h1 into newHeader
        newHeader.setAttributes(h1.getAttributes());
        //for i in uniqueCols:
        //copy h2[i] into newHeader
        for (unsigned int i = 0; i < uniqueCols.size(); ++i) {
            newHeader.push_back(h2.at(uniqueCols.at(i)));
        }
        return newHeader;
    }

    bool isJoinable(Tuple& t1, Tuple& t2, vector<pair<unsigned int, unsigned int>> overlap) {
        for (pair<unsigned int, unsigned int> currPair : overlap) {
            if (t1.at(currPair.first) != t2.at(currPair.second)) {
                return false;
            }
        }
        return true;
    }

    Tuple combineTuples(Tuple& t1, Tuple& t2, vector<unsigned int> uniqueCols) {
        //let newTuple be a new empty tuple
        Tuple newTuple;
        //copy all values from t1 into newTuple
        newTuple.setValues(t1.getValues());
        for (unsigned int i = 0; i < uniqueCols.size(); ++i) {
            newTuple.push_back(t2.at(uniqueCols.at(i)));
        }
        return newTuple;
    }
};

#endif //PROJECT1LEXER_RELATION_H
