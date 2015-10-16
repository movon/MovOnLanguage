#ifndef PARSER_H
#define PARSER_H

#include <vector>
#include <string>
#include "Node.h"
#include "Tok.h"
#include "ParentNode.h"
#include "TokStreamer.h"
#include "Lexer.h"
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
    static void run(std::vector<Tok> toks);

    static void createNode(Node* parent, NodeType nodeType);

    static void createNode(Node* parent, NodeType nodeType, Tok t);
private:

    static bool expect(Tok& tok, tokType t);

    static bool accept(Tok& tok, tokType t);

    static void handleKeywords(Tok currentTok, TokStreamer* streamer);

    static void Print(TokStreamer* streamer);

    static void handleTypes(Tok& currentTok, TokStreamer* streamer);

	static bool termByType(tokType t, TokStreamer* st);

	static bool termByValue(std::string s, TokStreamer* st);

    //Grammar Functions

    static bool termByType(tokType t, TokStreamer* st);

    static bool termByValue(std::string s, TokStreamer* st);

    static bool LOne(TokStreamer* st);

    static bool LOne1(TokStreamer* st);

    static bool LOne2(TokStreamer* st);

    static bool LTwo(TokStreamer* st);

    static bool LTwo1(TokStreamer* st);

    static bool LTwo2(TokStreamer* st);

    static bool E(TokStreamer* st);

    static bool E1(TokStreamer* st);

    static bool E2(TokStreamer* st);

    static bool E3(TokStreamer* st);

    static bool E4(TokStreamer* st);

    static bool E5(TokStreamer* st);

    static bool T(TokStreamer* st);

    static bool T1(TokStreamer* st);

    static bool F(TokStreamer* st);

    static bool F1(TokStreamer* st);

    static bool P(TokStreamer* st);

    static bool P1(TokStreamer* st);

    static bool P2(TokStreamer* st);

    static bool P3(TokStreamer* st);

    static bool P4(TokStreamer* st);

    static bool V(TokStreamer* st);
    
    static bool V1(TokStreamer* st);
    
    static bool V2(TokStreamer* st);
    
    static bool V3(TokStreamer* st);

};


#endif //PARSER_H