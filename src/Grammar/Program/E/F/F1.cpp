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
				f->addChild(Node::createNode(f, NodeType::EXPO));
				f->addChild(F_Node);
            }
            else {
                error("Expected another term after operator \"^\"");
            }
        }
		else {
			st->setIndex(save);
		}
        return f;
    }
    
    return nullptr;
}