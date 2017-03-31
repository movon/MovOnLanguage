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

bool Node::equals(Node* other) {
	if(other == nullptr) return false;
	
	if(this->nodeType != other->nodeType) {
		std::cout << "nodes are not equal because the types are different."<< std::endl;
		return false;
	}
		
	if(!this->t.equals(other->t)) {
		// std::cout << "nodes are not equal because their tokens are different. node1 token: (" << this->t.type << "," << this->t.content << ") .  node2 token: (" << other->t.type << "," << other->t.content << ")" << std::endl;
		std::cout << "nodes are not equal because their tokens are different. node1 token type: (" << this->t.content << ") .  node2 token type: (" << other->t.content << ")" << std::endl;
		return false;
	}
		
	if(children.size() != other->getChildren().size()) {
		std::cout << "nodes are not equal because they have a different ammount of children. this has " << children.size() << " and the other has " << other->getChildren().size() << std::endl;
		return false;
	}
		
	
	for(int i = 0; i < children.size(); i++) {
		if(!children.at(i)->equals(other->getChild(i)))
			return false;
	}
	
	return true;
	
}





