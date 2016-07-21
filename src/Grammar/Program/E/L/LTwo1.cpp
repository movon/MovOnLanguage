#include "LTwo1.h"

Node* LTwo1::tryParse(TokStreamer* ts) {
    if (termByValue("*", ts)) {
		return (Node::createNode(nullptr, NodeType::MUL));
    }

    return nullptr;
}