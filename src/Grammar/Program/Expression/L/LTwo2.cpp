#include "LTwo2.h"

Node* LTwo2::tryParse(TokStreamer* ts) {
    if (termByValue("/", ts)) {
		return Node::createNode(nullptr, NodeType::DIV);
    }

    return nullptr; 
}