#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Token.h"
#include "Lexer.h"
#include "Parser.h"

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
        //parser.run();         //TODO create this run method to run it all together
        cout << "Total Tokens = " << tokens.size();
    }
    catch(Token errorToken) {
        cout << "Failure!" << endl << " " << errorToken.toString();
    }

    return 0;
}
