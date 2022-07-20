#ifndef PROJECT1LEXER_DATABASE_H
#define PROJECT1LEXER_DATABASE_H
#include "Relation.h"
#include <map>

class Database {
private:
    map<string, Relation*> database;

public:
    Database() {}

    Database(const map<string, Relation *> &database) : database(database) {}
    //this class is just a map that holds all the relations,
    //not much code will be here other than adding relations
    //and potentially adding tuples

    const map<string, Relation*> &getDatabase() const {
        return database;
    }

    void setDatabase(const map<string, Relation*> &database) {
        Database::database = database;
    }

    void addRelation(string name, Relation* relation) {
        database.insert({name, relation});
    }

    Relation* getRelation(string name) {
        //return the relation at that point
        //use this-> to get the relation you want, then add fact data to it
        Relation* relation = database.at(name);
        return relation;
    }
};

#endif //PROJECT1LEXER_DATABASE_H
