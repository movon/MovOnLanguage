#include "T.h"

Node* T::tryParse(TokStreamer* st) {
    int save = st->getIndex();
    Node* T_Node = T1.tryParse(st);
	if (T_Node != nullptr) {
        return T_Node;
    }

	st->setIndex(save);
    return nullptr;
}