#include "V2.h"


Node* V2::tryParse(TokStreamer* st) {
    if (termByType(tokType::IDENTIFIER, st)) {
		Node* V = Node::createNode(nullptr, NodeType::ID, st->getLastToken(1));
		return V;
    }

    return nullptr;
}