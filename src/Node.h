#ifndef NODE_H
#define NODE_H

#include <string>
#include "Tok.h"
#include <vector>

enum class NodeType { CMP, TEST, WHILE, FOR, FUNCTIONCALL, STRING, INT, FLOAT, CREATION, ASSIGNMENT, E};

class Node{
protected:
    NodeType nodeType;
    std::vector<Node*> children;
    Node* parent;
public:
    Node(Node* parent, NodeType nodeType, std::vector<Tok> tokens);
    Node();
    ~Node();
    void addChild(Node* node);
    void changeToks(std::vector<Tok>toks);

    Node* getChild(int i);
    void disownAllChildren();
    int numChildren();
    void changeParent(Node* Parent);
};


#endif
