#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Token.h"
#include "Lexer.h"
#include "Parser.h"
#include "Relation.h"
#include "DatalogProgram.h"

using namespace std;

//int main(int argc, char* argv[]) {
//    ifstream inputFile(argv[1]);
//    string stringFile;
//    stringFile.assign((istreambuf_iterator<char>(inputFile)), (istreambuf_iterator<char>()));
//
//    vector<Token> tokens;
//    Lexer lexer;
//    tokens = lexer.run(stringFile);
//
//    try {
//        Parser parser = Parser(tokens);
//        DatalogProgram program = parser.run();
//        cout << "Success!" << endl;
//        cout << program.toString();
//    }
//    catch(Token errorToken) {
//        cout << "Failure!" << endl << " " << errorToken.toString();
//    }
//    catch(const char* errorMsg) {
//        cout << errorMsg;
//    }
//
//    return 0;
//}

int main() {
    Relation r;
    Header h({"S", "N", "A", "P"});
    r.setHeader(h);

    Tuple t1({"\'12345\'", "\'Charlie\'", "\'12 Apple St.\'", "\'555-1234\'"});
    Tuple t2({"\'67890\'", "\'Lucy\'", "\'34 Pear Ave.\'", "\'555-5678\'"});
    Tuple t3({"\'33333\'", "\'Snoopy\'", "\'12 Apple St.\'", "\'555-1234\'"});

    r.addTuple(t1);
    r.addTuple(t2);
    r.addTuple(t3);
    cout << r.toString();

    return 0;
}