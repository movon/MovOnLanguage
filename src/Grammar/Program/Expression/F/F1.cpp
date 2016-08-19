#include "F1.h"

Node* F1::tryParse(TokStreamer* st) {
    Node* f;
    P& p = P::getInstance();
    F& fParser = F::getInstance();
    Node* P_Node = nullptr;
    Node* F_Node = nullptr;
    P_Node = p.tryParse(st);
    if (P_Node != nullptr) {
		f = Node::createNode(nullptr, NodeType::E);
		f->addChild(P_Node);
		int save = st->getIndex();
        if (termByValue("^", st)) {
            F_Node = fParser.tryParse(st);
            if (F_Node != nullptr) {
				Node::createNode(f, NodeType::EXPO, Tok("^", tokType::OPERATOR));
				f->addChild(F_Node);
				return f;
            }
            else {
                error("Expected another term after operator \"^\"");
            }
        }
		else {
			st->setIndex(save);
		}
        return P_Node;
    }
    
    return nullptr;
}