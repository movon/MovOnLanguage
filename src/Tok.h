#include <iostream>
#include <string>

#ifndef TOK_H
#define TOK_H

enum class tokType { NONE, IDENTIFIER, KEYWORD, FUNCTIONNAME, PARAM, STRING, DELIMITER, OPERATOR, INT, FLOAT, FLOWOPERATOR, OPENPARAN, CLOSINGPARAN, OPENCURLY, CLOSINGCURLY, FUNCTIONDEF, COMMA, ASSIGNMENT, ENDOFINPUT, TYPE, COMPAREOPERATOR };

class Tok {


public:
    std::string content;
    tokType type;
    Tok(std::string con, tokType ty);
    Tok();


};


#endif
