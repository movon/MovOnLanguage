#include "Expression1.h"


Node* E1::tryParse(TokStreamer* st) {
    Node* E;
    T& t = T::getInstance();
    LOne& lOne = LOne::getInstance();
    Node* T_Node = nullptr;
    Node* LOne_Node = nullptr;
	if (T_Node = t.tryParse(st)) {
		//maybe Node::createNode
		E = Node::createNode(nullptr, NodeType::E);
		E->addChild(T_Node);
		LOne_Node = lOne.tryParse(st);
		while (LOne_Node != nullptr) {
			
			//maybe Node::createNode
			if (E->numChildren() == 1) {
				E->addChild(LOne_Node);
				if (T_Node = t.tryParse(st)) {
					E->addChild(T_Node);
					

				}
				// else {
				// 	error("Expected another term after operator \"+\" or \"-\"");
				// }
			}
			else {
				//Unite the children into an Expression
				Node* newE = Node::createNode(nullptr, NodeType::E);
				newE->addChild(E);
				Node* temp = newE;
				newE = E;
				E = temp;
				E->addChild(LOne_Node);
				if (T_Node = t.tryParse(st)) {
					E->addChild(T_Node);
				}
				// else {
				// 	error("Expected another term after operator \"+\" or \"-\"");
				// }
			}
			LOne_Node = lOne.tryParse(st);
		}
		return E;
    }
    return nullptr;
}