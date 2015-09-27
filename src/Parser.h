#ifndef PARSER_H
#define PARSER_H

#include <vector>
#include <string>
#include "Node.h"
#include "Tok.h"
#include "ParentNode.h"
#include "TokStreamer.h"

class Parser{
public:
    static void run(std::vector<Tok> toks);

    static void createNode(Node* parent, NodeType nodeType, std::vector<Tok> tokens);
private:

    static bool expect(Tok& tok, tokType t);

    static bool accept(Tok& tok, tokType t);

    static void handleKeywords(Tok currentTok, TokStreamer* streamer);

    static void Print(TokStreamer* streamer);

    static void handleTypes(Tok& currentTok, TokStreamer* streamer);
};


#endif //PARSER_H