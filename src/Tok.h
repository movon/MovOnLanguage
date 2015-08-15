#include <iostream>
#include <string>

#ifndef MOVONLANGUAGE_TOK_H
#define MOVONLANGUAGE_TOK_H


enum tokType { NONE = 0, VARIABLE = 1, KEYWORD = 2, FUNCTION = 3, PARAM = 4, STRING = 5, DELIMITER = 6, OPERATOR = 7, INT = 8};

class Tok {


public:
    std::string content;
    tokType type;
    Tok(std::string con, tokType ty);


};


#endif //MOVONLANGUAGE_TOK_H
