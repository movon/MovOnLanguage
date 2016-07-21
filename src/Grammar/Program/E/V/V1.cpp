#include "V1.h"


Node* V1::tryParse(TokStreamer* ts) {
    if (termByType(tokType::INT, ts)) {
		return Node::createNode(nullptr, NodeType::INT, ts->getLastToken(1));
    }

    return nullptr;
}