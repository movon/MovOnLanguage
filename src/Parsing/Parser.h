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

     bool Program(TokStreamer* st);
    
     bool Program1(TokStreamer* st);
    
     bool FunctionDef(TokStreamer* st);
    
     bool termByType(tokType t, TokStreamer* st);
    
     bool termByValue(std::string s, TokStreamer* st);
    
     bool LOne(TokStreamer* st);
    
     bool LOne1(TokStreamer* st);
    
     bool LOne2(TokStreamer* st);
    
     bool LTwo(TokStreamer* st);
    
     bool LTwo1(TokStreamer* st);
    
     bool LTwo2(TokStreamer* st);
    
     bool E(TokStreamer* st);
    
     bool E1(TokStreamer* st);
    
     bool E2(TokStreamer* st);
    
     bool E3(TokStreamer* st);
    
     bool E4(TokStreamer* st);
    
     bool E5(TokStreamer* st);
    
     bool T(TokStreamer* st);
    
     bool T1(TokStreamer* st);
    
     bool F(TokStreamer* st);
    
     bool F1(TokStreamer* st);
    
     bool P(TokStreamer* st);
    
     bool P1(TokStreamer* st);
    
     bool P2(TokStreamer* st);
    
     bool P3(TokStreamer* st);
    
     bool P4(TokStreamer* st);
    
     bool V(TokStreamer* st);
    
     bool V1(TokStreamer* st);
    
     bool V2(TokStreamer* st);
    
     bool V3(TokStreamer* st);

};


#endif //PARSER_H