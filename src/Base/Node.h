#ifndef NODE_H
#define NODE_H


#include <iostream>
#include <string>
#include "Tok.h"
#include <vector>

enum class NodeType { CMP = 0, TEST = 1, WHILE = 2, FOR = 3, FUNCTIONCALL = 4, STRING = 5, INT = 6, FLOAT = 7, CREATION = 8, ASSIGNMENT = 9, E = 10, CREMENTER = 11, ADD = 12, SUB = 13, MUL = 14, DIV = 15, EXPO = 16, PARENT = 18, ID = 19, PIPELINE = 999};

class Node{
protected:
    std::vector<Node*> children;
    Node* parent;
    std::string name;
public:
	NodeType nodeType;
	Tok t;
	std::string drawName = "";
    Node(Node* Parent, NodeType Nodetype);
    Node(Node* Parent, NodeType Nodetype, Tok T);
    Node(NodeType Nodetype, std::string Name);
    Node();
    ~Node();
    void addChild(Node* node);
    void changeTok(Tok T);

    Node* getChild(int i);
    void disownAllChildren();
    int numChildren();
    void changeParent(Node* Parent);
	std::vector<Node*> getChildren();
    void setChildren(std::vector<Node*> children);

	bool equals(Node* other);
	
	
	
	static Node* createNode(Node* parent, NodeType nodeType);
    static Node* createNode(Node* parent, NodeType nodeType, Tok t);
};


#endif
