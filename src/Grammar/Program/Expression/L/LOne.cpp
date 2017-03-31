#include "LOne.h"

Node* LOne::tryParse(TokStreamer* ts) {
    int save = ts->getIndex();
    Node* LOne_Node;
    if (LOne_Node = LOne1::tryParse(ts)) {
        //maybe Node::createNode
        return LOne_Node;
    }

    ts->setIndex(save);
    LOne_Node = LOne2::tryParse(ts);
    if (LOne_Node != nullptr) {
        //maybe Node::createNode
        return LOne_Node;
    }

	ts->setIndex(save);
    return nullptr;
}