#include "P3.h"


Node* P3::tryParse(TokStreamer* ts) {
    Node* P = Node::createNode(nullptr, NodeType::E);
    if (termByValue("-", ts)) {
        if (Node* T_Node = T::tryParse(ts)) {
			P->addChild(Node::createNode(P, NodeType::SUB));
			P->addChild(T_Node);
            return P;
        }
        else {
            error("Expected a term after unirary minus sign");
        }
    }
    
    return nullptr;
}