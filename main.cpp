#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Token.h"
#include "Lexer.h"

using namespace std;

int main(int argc, char* argv[]) {
    ifstream inputFile(argv[1]);
    string stringFile;
    stringFile.assign((istreambuf_iterator<char>(inputFile)), (istreambuf_iterator<char>()));

    vector<Token> tokens;
    Lexer lexer;
    try {
        tokens = lexer.run(stringFile);
    } catch(const char* errorMsg) {
        cout << errorMsg;
    }
    cout << "Total Tokens = " << tokens.size();
    cout << endl;

    return 0;
}
