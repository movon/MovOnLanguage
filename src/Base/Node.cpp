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

Node::Node(NodeType Nodetype, std::string Name) {
	nodeType = Nodetype;
	name = Name;
}

Node::Node() {}

Node::~Node() {
	for (int i = 0;i < children.size();i++) {
		delete children.at(i);
	}
}

Node* Node::createNode(Node* parent, NodeType nodeType){
    Node* node = new Node(parent, nodeType);
    if(parent != nullptr) {
       parent->addChild(node);
    }
	
    return node;
}

Node* Node::createNode(Node* parent, NodeType nodeType, Tok t) {
    Node* node = new Node(parent, nodeType, t);
    if (parent != nullptr) {
        parent->addChild(node);
    }

    return node;
}

void Node::addChild(Node* node) {
	 children.push_back(node);
	 node->changeParent(this);
}

void Node::changeTok(Tok T){
	t = T;
}

Node* Node::getChild(int i) {
	return children.at(i);
}

void Node::disownAllChildren() {
	children.clear();
}

int Node::numChildren() {
	return children.size();
}

void Node::changeParent(Node* Parent) {
	parent = Parent;
}
std::vector<Node*> Node::getChildren()
{
	return children;
}




void Node::print() {
	for(Node* child : children) {
		child->print();
	}
}