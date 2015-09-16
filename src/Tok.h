#ifndef TOK_H
#define TOK_H

#include <iostream>
#include <string>

enum class tokType { NONE, IDENTIFIER, KEYWORD, FUNCTION, PARAM, STRING, DELIMITER, OPERATOR, INT, FLOAT, FLOWOPERATOR, OPENPARAN, CLOSINGPARAN, OPENCURLY, CLOSINGCURLY };

class Tok {


public:
    std::string content;
    tokType type;
    Tok(std::string con, tokType ty);


};


#endif //MOVONLANGUAGE_TOK_H