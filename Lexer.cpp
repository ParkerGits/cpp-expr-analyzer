#include "Lexer.h"
#include <iostream>
#include <sstream>

Lexer::Lexer(string& sourceChars) {
  _sourceChars = sourceChars.begin();
  _sourceEnd = sourceChars.end();
  if (_sourceChars == _sourceEnd) {
    _nextChar = '\0';
    return;
  }
  _nextChar = *_sourceChars;
}

Lexer::LexemeToken Lexer::Lex() {
  if (_sourceChars == _sourceEnd) return {"\0", NONE};
  LexemeToken ret;
  stringstream lexeme;
  if(isdigit(_nextChar)) {
    do {
      lexeme << _nextChar;
      LoadNextChar();
    } while(isdigit(_nextChar));
  }
  else {
    lexeme << _nextChar;
    LoadNextChar();
  }
  ret.lexeme = lexeme.str();
  ret.token = Lookup(lexeme.str());
  return ret;
}

Lexer::Token Lexer::Lookup(const string& lexeme) {
  if (lexeme == "=") return ASSIGN;
  if (lexeme == "(") return LPAREN;
  if (lexeme == ")") return RPAREN;
  if (lexeme == "+") return ADD_OP;
  if (lexeme == "*") return MULTIPLY_OP;
  if (lexeme.size() == 1 && isalpha(lexeme.at(0)) && islower(lexeme.at(0))) return ID;
  for (auto &c : lexeme) {
    if (!isdigit(c)) {
      cout << "Lexical Error: " << c << endl;
      exit(EXIT_FAILURE);
    }
  }
  return NUM;
}

void Lexer::LoadNextChar() {
  if(_sourceChars == _sourceEnd) {
    _nextChar = '\0';
  }
  _nextChar = *++_sourceChars;
}

void Lexer::PrintLexemes() {
  while (_sourceChars != _sourceEnd) {
    cout << Lex().token << endl;
  }
}