#ifndef PARSER_H
#define PARSER_H

#include "Lexer.h"

class Parser {
private:
  string Assign();
  string Expr();
  string Term();
  string Factor();
  string Id();
  string Num();
  Lexer _lexer;
  Lexer::LexemeToken _next;
public:
  Parser(string &source_chars);
  string Start();
};

#endif