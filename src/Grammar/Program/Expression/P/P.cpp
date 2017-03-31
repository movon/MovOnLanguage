#include "P.h"

Node* P::tryParse(TokStreamer* st) {
    int save = st->getIndex();
    Node* P_Node;

    if (P_Node = P1::tryParse(st)) {
        //maybe Node::createNode
        return P_Node;
    }
    
    st->setIndex(save);
    if (P_Node = P2::tryParse(st)) {
        //maybe Node::createNode
        return P_Node;
    }

    st->setIndex(save);
    if (P_Node = P3::tryParse(st)) {
        //maybe Node::createNode
        return P_Node;
    }

	st->setIndex(save);
    return nullptr;
};