#ifndef PROJECT1LEXER_RELATION_H
#define PROJECT1LEXER_RELATION_H
#include <set>
#include "Header.h"
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

    //B == C
    //A == "purple"
    Relation select(unsigned int col, string value) {
        Relation outputRelation;
        outputRelation.setHeader(this->header);
        outputRelation.setName("SELECT(" + this->name + ")");

        for (Tuple currTuple : tuples) {
            if (currTuple.at(col) == value) {
                outputRelation.addTuple(currTuple);
            }
        }
        return outputRelation;
    }

    Relation select(unsigned int col1, unsigned int col2) {
        Relation output;
        output.setHeader(header);
        output.setName(name);

        for (Tuple currTuple : tuples) {
            if (currTuple.at(col1) == currTuple.at(col2)) {
                output.addTuple(currTuple);
            }
        }
        return output;
    }

    //A <- B
    //[A,B,C] <- [E,F,G]
    Relation rename(unsigned int colToRename, string newName) {
        Relation output;
        output.setName(name);
        Header newHeader = header;
        newHeader.at(colToRename) = newName;
        output.setHeader(newHeader);
        output.setTuples(tuples);
        return output;
    }

    //pi_{BCD} R
    Relation project(vector<unsigned int> colsToKeep) {
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
