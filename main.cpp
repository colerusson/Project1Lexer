#include <iostream>
#include "Token.h"
#include "Automaton.h"
#include "Lexer.h"
#include <string>

using namespace std;

int main() {
    Token token = Token(COMMA, ",", 42);
    cout << token.toString();
    return 0;
}
