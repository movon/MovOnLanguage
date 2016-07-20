#include "E1.h"


Node* E1::tryParse(TokStreamer* st) {
    Node* E;
	if (T::tryParse(st) != NULL) {
		//maybe Node::createNode
		Node* result;
		result = nodes.back();
		nodes.pop_back();
		E = Node::createNode(nullptr, NodeType::E);
		E->addChild(result);
		while (LOne()) {
			//maybe Node::createNode
			if (E->numChildren() == 1) {
				result = nodes.back();
				nodes.pop_back();
				E->addChild(result);
				if (T()) {
					result = nodes.back();
					nodes.pop_back();
					E->addChild(result);
				}
				// else {
				// 	error("Expected another term after operator \"+\" or \"-\"");
				// }
			}
			else {
				//Unite the children into an E
				Node* newE = Node::createNode(nullptr, NodeType::E);
				newE->addChild(E);
				Node* temp = newE;
				newE = E;
				E = temp;
				result = nodes.back();//LOne
				nodes.pop_back();
				E->addChild(result);
				if (T()) {
					result = nodes.back();
					nodes.pop_back();//T
					E->addChild(result);
				}
				// else {
				// 	error("Expected another term after operator \"+\" or \"-\"");
				// }
			}
		}
		return E;
    }
    return NULL;
}