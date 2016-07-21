#include "LOne.h"

Node* LOne::tryParse(TokStreamer* ts) {
    int save = ts->getIndex();
    Node* LOne_Node;
    if (LOne_Node = LOne1::getInstance().tryParse(ts)) {
        //maybe Node::createNode
        return LOne_Node;
    }

    ts->setIndex(save);
    if (LOne_Node = LOne2::getInstance().tryParse(ts)) {
        //maybe Node::createNode
        return LOne_Node;
    }

	ts->setIndex(save);
    return nullptr;
}