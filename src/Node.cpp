#include "Node.h"


Node::Node(Node* Parent, NodeType Nodetype, std::vector<Tok> Tokens){
    parent = Parent;
    nodeType = Nodetype;
    tokens = Tokens;
}

Node::Node() {}

void Node::addChild(Node* node) {
	 children.push_back(node);
}