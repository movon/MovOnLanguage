#include "V2.h"


Node* V2::tryParse(TokStreamer* ts) {
    if (termByType(tokType::IDENTIFIER, ts)) {
		Node* V = Node::createNode(nullptr, NodeType::ID, ts->getLastToken(1));
		return V;
    }

    return nullptr;
}