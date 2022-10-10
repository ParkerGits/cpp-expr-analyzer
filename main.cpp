#include <iostream>
#include "Lexer.h"
#include "Parser.h"

using namespace std;

int main() {
  string source = "a=(8+2)+3";
  Lexer lexer(source);
  lexer.PrintLexemes();
  Parser parser(source);
  string out = parser.Start();
  cout << out << endl;
}