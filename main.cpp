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

int main(int argc, char* argv[]) {
    ifstream inputFile(argv[1]);
    string stringFile;
    stringFile.assign((istreambuf_iterator<char>(inputFile)), (istreambuf_iterator<char>()));

    vector<Token> tokens;
    Lexer lexer;
    tokens = lexer.run(stringFile);

    try {
        Parser parser = Parser(tokens);
        DatalogProgram program = parser.run();
        cout << "Success!" << endl;
        cout << program.toString();
    }
    catch(Token errorToken) {
        cout << "Failure!" << endl << " " << errorToken.toString();
    }
    catch(const char* errorMsg) {
        cout << errorMsg;
    }

    return 0;
}
