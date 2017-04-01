#include "V3.h"


Node* V3::tryParse(TokStreamer* st) {
    if (termByType(tokType::FLOAT, st)) {
		Node* V = Node::createNode(nullptr, NodeType::FLOAT, st->getLastToken(1));
        return V;
    }

    return nullptr;
}