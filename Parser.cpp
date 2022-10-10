#include "Parser.h"
#include <sstream>
#include <iostream>

Parser::Parser(string &sourceChars): _lexer(sourceChars) {
  _next = _lexer.Lex();
}

string Parser::Start() {
  stringstream ss;
  ss << Assign();
  return ss.str();
}

string Parser::Assign() {
  stringstream ss;
  ss << "<assign>";
  
  // handle ident
  ss << Id();

  // handle assign
  if (_next.token != Lexer::ASSIGN) {
    cout << "Syntax Error: assign expected" << endl;
    exit(EXIT_FAILURE);
  }
  ss << _next.lexeme;
  _next = _lexer.Lex();

  // handle expression
  ss << Expr();

  ss << "</assign>";
  return ss.str();
}

string Parser::Expr() {
  stringstream ss;
  ss << "<expr>";

  // handle term
  ss << Term();

  // handle multiple terms
  while (_next.token == Lexer::ADD_OP) {
    ss << _next.lexeme;
    _next = _lexer.Lex();
    ss << Term();
  }

  ss << "</expr>";
  return ss.str();
}

string Parser::Term() {
  stringstream ss;
  ss << "<term>";

  // handle factor
  ss << Factor();

  while(_next.token == Lexer::MULTIPLY_OP) {
    ss << _next.lexeme;
    _next = _lexer.Lex();
    ss << Factor();
  }

  ss << "</term>";
  return ss.str();
}

string Parser::Factor() {
  stringstream ss;
  ss << "<factor>";

  // check (<expr>)
  if(_next.token == Lexer::LPAREN) {
    // handle lparen
    ss << _next.lexeme;
    _next = _lexer.Lex();

    //handle expr
    ss << Expr();

    // handle rparen
    if(_next.token != Lexer::RPAREN) {
      cout << "Syntax Error: rparen expected" << endl;
      exit(EXIT_FAILURE);
    }
    ss << _next.lexeme;
    _next = _lexer.Lex();
  }
  // check id
  else if(_next.token == Lexer::ID) {
    // handle id
    ss << Id();
  }
  // check num
  else if(_next.token == Lexer::NUM) {
    // handle num
    ss << Num();
  }
  else {
    cout << "Syntax Error: lparen, id, or num expected" << endl;
    exit(EXIT_FAILURE);
  }

  ss << "</factor>";
  return ss.str();
}

string Parser::Id() {
  if (_next.token != Lexer::ID) {
    cout << "Syntax Error: id expected" << endl;
    exit(EXIT_FAILURE);
  }
  stringstream ss;
  ss << "<id>";
  ss << _next.lexeme;
  _next = _lexer.Lex();
  ss << "</id>";
  return ss.str();
}

string Parser::Num() {
if (_next.token != Lexer::NUM) {
    cout << "Syntax Error: num expected" << endl;
    exit(EXIT_FAILURE);
  }
  stringstream ss;
  ss << "<num>";
  ss << _next.lexeme;
  _next = _lexer.Lex();
  ss << "</num>";
  return ss.str();
}

