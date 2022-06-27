#include <iostream>
#include <fstream>
#include "Token.h"
#include "Automaton.h"
#include "Lexer.h"
#include <string>

using namespace std;

int main(int argc, char* argv[]) {
    ifstream inputFile(argv[1]);
    string stringFile;
    stringFile.assign((istreambuf_iterator<char>(inputFile)), (istreambuf_iterator<char>()));



    Token token = Token(COMMA, ",", 42);
    cout << token.toString();
    //TODO build everything else
    //TODO finish project by tuesday
    //TODO get the rest of the tokens
    return 0;
}
