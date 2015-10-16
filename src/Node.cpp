#include "Node.h"


Node::Node(Node* Parent, NodeType Nodetype){
    parent = Parent;
    nodeType = Nodetype;
}

Node::Node(Node* Parent, NodeType Nodetype, Tok T) {
	parent = Parent;
	nodeType = Nodetype;
	t = T;
}

Node::Node() {}

Node::~Node() {
	for (int i = 0;i < children.size();i++) {
		delete children.at(i);
	}
}

void Node::addChild(Node* node) {
	 children.push_back(node);
	 node->changeParent(this);
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

int Node::numChildren() {
	return children.length();
}

void Node::changeParent(Node* Parent) {
	parent = Parent;
}
