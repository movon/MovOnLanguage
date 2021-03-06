#include "Expression3.h"

Node* E3::tryParse(TokStreamer* ts) {
    if (termByType(tokType::IDENTIFIER, ts)) {//we need to see how we get this identifiers name
        if (termByValue("+", ts) && termByValue("+", ts)) {
			Tok name = ts->getLastToken(3);
			Node* C = Node::createNode(nullptr, NodeType::CREMENTER);
			C->addChild(Node::createNode(C, NodeType::ID,name));
			C->addChild(Node::createNode(C, NodeType::ADD));
            return C;
        }
// 		else{
// 			error("Expected an identifier before \"++\" operation");
// 		}
    }

    return nullptr;
}