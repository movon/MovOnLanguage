#include "ParentNode.h"

ParentNode::ParentNode(Node *parent, NodeType nodeType, std::vector<Tok> tokens, std::string Name) : Node(parent,nodeType,tokens) {
	name = Name;
}
