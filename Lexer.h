#ifndef LEXER_H
#define LEXER_H

#include <string>
using namespace std;

class Lexer {
public:
  enum Token {
    ID,
    ASSIGN,
    LPAREN,
    RPAREN,
    NUM,
    ADD_OP,
    MULTIPLY_OP,
    NONE
  };
  struct LexemeToken {
    string lexeme;
    Token token;
  };
  Lexer(string& sourceChars);
  LexemeToken Lex();
  void PrintLexemes();
private:
  string::iterator _sourceChars;
  string::iterator _sourceEnd;
  char _nextChar;
  Token Lookup(const string& lexeme);
  void LoadNextChar();
};

#endif