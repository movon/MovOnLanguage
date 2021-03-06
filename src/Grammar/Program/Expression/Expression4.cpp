#include "Expression4.h"

Node* E4::tryParse(TokStreamer* ts) {
    if (termByValue("-", ts) && termByValue("-", ts)) {
        if (termByType(tokType::IDENTIFIER, ts)) {//we need to see how we get this identifiers name
            Tok id = ts->getLastToken(1);
            Node* C = Node::createNode(nullptr, NodeType::CREMENTER);
            C->addChild(Node::createNode(C, NodeType::SUB));
            C->addChild(Node::createNode(C, NodeType::ID, id));
            return C;
        }
        // else {
        //     error("Expected an identifier after \"++\" operation");
        // }
    }

    return nullptr;
}
