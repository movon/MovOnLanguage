#include "LOne2.h"


Node* LOne2::tryParse(TokStreamer* ts) {
    if (termByValue("-", ts)) {
		return Node::createNode(nullptr, NodeType::SUB); 
    }

    return nullptr;
}