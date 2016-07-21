#include "T1.h"

Node* T1::tryParse(TokStreamer* st) {
    Node* T, result;
    Node* LTwo_Node = nullptr;
	Node* F_Node = nullptr;
	if (F_Node = F::getInstance().tryParse(st)) {
		T = Node::createNode(nullptr, NodeType::E);
		T->addChild(F_Node);
		while (LTwo_Node = LTwo::getInstance().tryParse(st)) {
			if (T->numChildren() == 1){
				T->addChild(LTwo_Node);
				if (F_Node = F::getInstance().tryParse(st)){
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
				if (F_Node = F::getInstance().tryParse(st)) {
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