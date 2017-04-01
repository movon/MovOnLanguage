#include "V1.h"


Node* V1::tryParse(TokStreamer* st) {
    if (termByType(tokType::INT, st)) {
		return Node::createNode(nullptr, NodeType::INT, st->getLastToken(1));
    }

    return nullptr;
}