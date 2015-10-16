#ifndef NODE_H
#define NODE_H

#include <string>
#include "Tok.h"
#include <vector>

enum class NodeType { CMP, TEST, WHILE, FOR, FUNCTIONCALL, STRING, INT, FLOAT, CREATION, ASSIGNMENT, E, CREMENTER, ADD, SUB, MUL, DIV, EXPO};

class Node{
protected:
    NodeType nodeType;
    std::vector<Node*> children;
    Node* parent;
    Tok t;
public:
    Node(Node* Parent, NodeType Nodetype);
    Node(Node* Parent, NodeType Nodetype, Tok T);
    Node();
    ~Node();
    void addChild(Node* node);
    void changeTok(Tok T);

    Node* getChild(int i);
    void disownAllChildren();
    int numChildren();
    void changeParent(Node* Parent);
};


#endif
