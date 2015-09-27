#ifndef NODE_H
#define NODE_H

#include <string>
#include "Tok.h"
#include <vector>

enum class NodeType { CMP, TEST, WHILE, FOR, FUNCTION };

class Node{
protected:
    NodeType nodeType;
    std::vector<Tok> tokens;
    std::vector<Node*> children;
    Node* parent;
public:
    Node(Node* parent, NodeType nodeType, std::vector<Tok> tokens);
    Node();
    void addChild(Node* node);
};


#endif
