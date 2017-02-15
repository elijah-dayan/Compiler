
/*Prog 4
  Mohammad Hossain (Rafsan)
  mmh318
  This is the lextest.cc provided file.I made some changes so that it
  corresponds my class variables and fucntions.
*/








#include "token.h"
#include "lexer.h"
#include <iostream>
#include <fstream>

using namespace std;

void processFile(istream& in) {
  Lexer lexer(in);
  Token token;

  token = lexer.nextToken();
  printf(" Type     Lexeme    Line #    Pos\n");
  while (token.getType() != Token::ENDOFFILE) {
    printf("%5d     %-10s %5d  %5d\n", token.getType(), token.getLexme().c_str(), token.getLine(), token.getPos());
    token = lexer.nextToken();
  }
}


int main(int argc, char **argv) {
  ifstream in;

  if (argc > 1) {
    in.open(argv[1]);
    processFile(in);
    in.close();
  } else {
    processFile(cin);
  }

}
