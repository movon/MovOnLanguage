#include "F1.h"

Node* F1::tryParse(TokStreamer* st) {
    Node* f,
    F_Node;
    if (P_Node = P.tryParse(st)) {
		f = Node::createNode(nullptr, NodeType::E);
		f->addChild(P_Node);
		nodes.pop_back();
		int save = st->getIndex();
        if (termByValue("^")) {
            if (F_Node = F.tryParse(st)) {
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