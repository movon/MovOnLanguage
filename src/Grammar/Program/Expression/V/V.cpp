#include "V.h"


Node* V::tryParse(TokStreamer* ts) {
    int save = ts->getIndex();
    Node* V_Node = nullptr;
    if (V_Node = V1::tryParse(ts)) {
        //maybe Node::createNode
        return V_Node;
    }

    ts->setIndex(save);
    if (V_Node = V2::tryParse(ts)) {
        return V_Node;
    }

    ts->setIndex(save);
    if (V_Node = V3::tryParse(ts)) {
        return V_Node;
    }
	
	ts->setIndex(save);
    return nullptr;
}