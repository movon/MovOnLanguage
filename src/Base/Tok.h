#include <iostream>
#include <string>

#ifndef MOVONLANGUAGE_TOK_H
#define MOVONLANGUAGE_TOK_H


// TODO give example for each type
enum class tokType { NONE = 0, IDENTIFIER = 1, KEYWORD = 2, FUNCTIONNAME = 3,
 PARAM = 4, STRING = 5, DELIMITER = 6, OPERATOR = 7, INT = 8, FLOAT = 9,
  FLOWOPERATOR = 10, OPENPARAN = 11, CLOSINGPARAN = 12, OPENCURLY = 13,
   CLOSINGCURLY = 14, FUNCTIONDEF = 15, COMMA = 16, ASSIGNMENT = 17,
    ENDOFINPUT = 18, TYPE = 19, COMPAREOPERATOR = 20};

class Tok {


public:
    std::string content;
    tokType type;
    Tok(std::string con, tokType ty);
    Tok();
    bool equals(Tok t);
};


#endif //MOVONLANGUAGE_TOK_H
