#include "V3.h"


Node* V3::tryParse(TokStreamer* ts) {
    if (termByType(tokType::FLOAT, ts)) {
		Node* V = Node::createNode(nullptr, NodeType::FLOAT, ts->getLastToken(1));
        return V;
    }

    return nullptr;
}