#include "LTwo.h"

Node* LTwo::tryParse(TokStreamer* ts) {
    int save = ts->getIndex();
    Node* LTwo_Node = nullptr;
    if (LTwo_Node = LTwo1::tryParse(ts)) {
        return LTwo_Node;
    }

    ts->setIndex(save);
    if (LTwo_Node = LTwo2::tryParse(ts)) {
        return LTwo_Node;
    }

	ts->setIndex(save);
    return nullptr;
}