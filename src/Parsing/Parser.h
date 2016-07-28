#ifndef PARSER_H
#define PARSER_H

#include <vector>
#include <string>
#include "../Base/Node.h"
#include "../Base/Tok.h"
#include "TokStreamer.h"
#include "../Grammar/Program/Program.h"
#include <set>
#include <fstream>
//Grammar for Expressions:
<<<<<<< HEAD
// Expression --> T {LOne T} | "+" "+" ID | ID "+" "+" | "-" "-" ID | ID "-" "-"
// T --> F {LTwo F}
// F --> P ["^" F]
// P --> V | "(" Expression ")" | "-" T | "+" T //V is constants and identifiers
=======
// E --> T {LOne T} | "+" "+" ID | ID "+" "+" | "-" "-" ID | ID "-" "-"
// T --> F {LTwo F}
// F --> P ["^" F]
// P --> V | "(" E ")" | "-" T | "+" T //V is constants and identifiers
>>>>>>> af25e5201f487a98dd50ca74b3091d9d21b2ffe9
// LOne -> "+" | "-"
// LTwo -> "*" | "/"

//Grammer for BEXP:
// BEXP -> lvl1bexp {OR lvl1bexp}
// lvl1bexp -> lvl2bexp {(AND|XOR) lvl2bexp}
// lvl2bexp -> NOT lvl3bexp | lvl3bexp
<<<<<<< HEAD
// lvl3bexp -> TRUE | FALSE | Expression COMPARISON_OPERATOR Expression
=======
// lvl3bexp -> TRUE | FALSE | E COMPARISON_OPERATOR E
>>>>>>> af25e5201f487a98dd50ca74b3091d9d21b2ffe9

class Parser{
public:
    void run(std::vector<Tok> toks);
    
private:

    TokStreamer* ts;
    
    Node* AST;
    
    std::vector<std::string> handle_node(Node* node);

	std::string nodeToRealString(Node* n);

	void drawNodes();
    
    int E_index = 0;
    int INT_index = 0;
    int ADD_index = 0;
    int SUB_index = 0;
    int MUL_index = 0;
    int DIV_index = 0;
    int EXPO_index = 0;
    
    void error(std::string errormsg); //Maybe this needs to be seperated to another class called Errors

};
#endif //PARSER_H