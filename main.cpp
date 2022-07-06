#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Token.h"
#include "Lexer.h"
#include "Parser.h"
#include "DatalogProgram.h"

using namespace std;

int main(int argc, char* argv[]) {

    ifstream inputFile(argv[1]);
    string stringFile;
    stringFile.assign((istreambuf_iterator<char>(inputFile)), (istreambuf_iterator<char>()));

    try {
        vector<Token> tokens;
        Lexer lexer;
        tokens = lexer.run(stringFile);
        Parser parser = Parser(tokens);
        parser.run();
        cout << "Success!";
    }
    catch(Token errorToken) {
        cout << "Failure!" << endl << " " << errorToken.toString();
    }

    /*DatalogProgram program;

    Predicate snapScheme;
    snapScheme.setName("snap");
    snapScheme.addParameter("S");
    snapScheme.addParameter("N");
    snapScheme.addParameter("A");
    snapScheme.addParameter("P");
    program.addScheme(snapScheme);

    Predicate addressScheme;
    addressScheme.setName("HasSameAddress");
    addressScheme.addParameter("X");
    addressScheme.addParameter("Y");
    program.addScheme(addressScheme);

    Predicate snapFact;
    snapFact.setName("snap");
    snapFact.addParameter("'12345'");
    snapFact.addParameter("'C.Brown'");
    snapFact.addParameter("'12 Apple'");
    snapFact.addParameter("'555-1234'");
    program.addFact(snapFact);

    Rule rulePredicate;
    rulePredicate.setHead(addressScheme);
    rulePredicate.addPredicate(snapScheme);
    rulePredicate.addPredicate(snapScheme);
    program.addRule(rulePredicate);

    cout << program.toString();*/

    return 0;
}
