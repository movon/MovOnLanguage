#ifndef PARSER_H
#define PARSER_H

#include <vector>
#include <string>
#include "../Base/Node.h"
#include "../Base/Tok.h"
#include "TokStreamer.h"
#include "../Lexing/Lexer.h"
#include <fstream>
//Grammar for Expressions:
// E --> T {LOne T} | "+" "+" ID | ID "+" "+" | "-" "-" ID | ID "-" "-"
// T --> F {LTwo F}
// F --> P ["^" F]
// P --> V | "(" E ")" | "-" T | "+" T //V is constants and identifiers
// LOne -> "+" | "-"
// LTwo -> "*" | "/"

//Grammer for BEXP:
// BEXP -> lvl1bexp {OR lvl1bexp}
// lvl1bexp -> lvl2bexp {(AND|XOR) lvl2bexp}
//lvl2bexp -> NOT lvl3bexp | lvl3bexp
//lvl3bexp -> TRUE | FALSE | E COMPARISON_OPERATOR E


class Parser{
public:
    void run(std::vector<Tok> toks);
    
private:

    TokStreamer* st;
    
    std::vector<std::string> handle_node(Node* node);

	std::string nodeToRealString(Node* n);

	void drawNodes();

	static void error(std::string errormsg);

    Node* currParent = nullptr;
    
    Node* prevNode = nullptr;
    
    std::vector<Tok> currentStatement;
    
    std::vector<Tok> prevStatement;
    
    std::vector<Node*> nodes;
    
    int E_index = 0;
    int INT_index = 0;
    int ADD_index = 0;
    int SUB_index = 0;
    int MUL_index = 0;
    int DIV_index = 0;
    int EXPO_index = 0;

    static bool expect(Tok& tok, tokType t);

    static bool accept(Tok& tok, tokType t);

    static void handleKeywords(Tok currentTok, TokStreamer* streamer);

    //static void Print(TokStreamer* streamer);

    //static void handleTypes(Tok& currentTok, TokStreamer* streamer);

    //Grammar Functions

     bool Program();
    
     bool Program1();
    
     bool FunctionDef();
    
     bool termByType(tokType t);
    
     bool termByValue(std::string s);
    
     bool LOne();
    
     bool LOne1();
    
     bool LOne2();
    
     bool LTwo();
    
     bool LTwo1();
    
     bool LTwo2();
    
     bool E();
    
     bool E1();
    
     bool E2();
    
     bool E3();
    
     bool E4();
    
     bool E5();
    
     bool T();
    
     bool T1();
    
     bool F();
    
     bool F1();
    
     bool P();
    
     bool P1();
    
     bool P2();
    
     bool P3();
    
     bool P4();
    
     bool V();
    
     bool V1();
    
     bool V2();
    
     bool V3();

};


#endif //PARSER_H