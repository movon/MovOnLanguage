#ifndef NODE_H
#define NODE_H

#include <string>
#include "Tok.h"
#include <vector>

enum class NodeType { CMP, TEST, WHILE, FOR, FUNCTION };

class Node{
protected:
    NodeType nodeType;
    std::vector<Tok> toks;
    std::vector<Node*> children;
    Node* parent;
    
    Node(Node* parent, NodeType nodeType, std::vector<Tok> tokens);
    ~Node();
    
    std::string toString();
}


#endif
