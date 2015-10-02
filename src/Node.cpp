#include "Node.h"


Node::Node(Node* Parent, NodeType Nodetype, std::vector<Tok> Tokens){
    parent = Parent;
    nodeType = Nodetype;
    tokens = Tokens;
}

Node::Node() {}

Node::~Node() {
	for (int i = 0;i < children.size();i++) {
		delete children.at(i);
	}
}

void Node::addChild(Node* node) {
	 children.push_back(node);
}

void Node::changeToks(std::vector<Tok> toks){
	tokens = toks;
}

Node* Node::getChild(int i) {
	return children.at(i);
}

void Node::disownAllChildren() {
	children.clear();
}

