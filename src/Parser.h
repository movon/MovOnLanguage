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

    void createNode(Node* parent, NodeType nodeType, std::vector<Tok> tokens);
private:
    ParentNode* prevParent = nullptr;
    Node* prevNode = nullptr;
    std::vector<Tok> currentStatement;
    std::vector<Tok> prevStatement;

    bool expect(Tok &tok, tokType &t);

    bool accept(Tok &tok, tokType &t);

    void handleKeywords(Tok currentTok, TokStreamer* streamer);

    void Print(TokStreamer* streamer);

    void handleTypes(TokStreamer* streamer);
};


#endif //PARSER_H