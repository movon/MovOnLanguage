#include "T1.h"

Node* T1::tryParse(TokStreamer* st) {
    Node* T,
    result,
	F_Node,
	LTwo_Node;
	if (F_Node = F.tryParse(st)) {
		T = Node::createNode(nullptr, NodeType::E);
		T->addChild(F_Node);
		while (LTwo_Node = LTwo.tryParse(st)) {
			if (T->numChildren() == 1){
				T->addChild(LTwo_Node);
				if (F_Node = F.tryParse(st)){
					T->addChild(F_Node);
				}
				else{
					error("expected a term after \"*\" or \"/\" ");
				}
			}
			else{
				Node* newE = Node::createNode(nullptr, NodeType::E);
				newE->addChild(T);
				Node* temp = newE;
				newE = T;
				T = temp;
				T->addChild(LTwo_Node);
				if (F_Node = F.tryParse(st)) {
					T->addChild(F_Node);
				}
				else{
					error("expected a term after \"*\" or \"/\" ");
				}
			}
		}
		return T;
    }
    
    return nullptr;
}