#ifndef PARSER_H
#define PARSER_H

#include <vector>
#include <string>
#include "Node.h"
#include "Tok.h"

class parser{
public:
    void run();

    void createNode(Node* parent, NodeType nodeType, std::vector<Tok> tokens);
    void createParentNode(std::string Name, NodeType nodeType, std::vector<Tok> tokens);
private:
    ParentNode* prevParent = nullptr;
    Node* prevNode = nullptr;
    std::vector<Tok> toks;
    std::vecor<Tok> currentStatement;
    std::vector<Tok> prevStatement;
};


#endif