#include "LOne1.h"

Node* LOne1::tryParse(TokStreamer* ts) {
    if (termByValue("+", ts)) {
		return (Node::createNode(nullptr, NodeType::ADD));
    }

    return nullptr;
}