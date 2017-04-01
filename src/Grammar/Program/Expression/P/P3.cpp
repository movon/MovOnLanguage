#include "P3.h"


Node* P3::tryParse(TokStreamer* st) {
    Node* P = Node::createNode(nullptr, NodeType::E);
    if (termByValue("-", st)) {
        Job TParser(&T::tryParse, st);
        TParser.executeTask();
        if(TParser.suceeded()) {
            P->addChild(Node::createNode(P, NodeType::SUB));
            P->addChild(TParser.getResult());
            return P;
        }
        else {
            error("Expected a term after unirary minus sign");
        }
    }
    return nullptr;
}