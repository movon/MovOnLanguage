#include "F.h"

Node* F::tryParse(TokStreamer* st) {
    int save = st->getIndex();
    Node* F_Node = F1::getInstance().tryParse(st);
	if (F_Node != nullptr) {
        return F_Node;
    }

	st->setIndex(save);
    return nullptr;
}