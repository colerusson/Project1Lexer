#include <iostream>
#include <fstream>
#include <string>
#include "Token.h"
#include "Lexer.h"

using namespace std;

int main(int argc, char* argv[]) {
    ifstream inputFile(argv[1]);
    string stringFile;
    stringFile.assign((istreambuf_iterator<char>(inputFile)), (istreambuf_iterator<char>()));

    vector<Token> tokens;
    Lexer lexer;
    tokens = lexer.run(stringFile);
    cout << "Total Tokens = " << tokens.size();
    cout << endl;

    return 0;
}
