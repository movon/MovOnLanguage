#include "P.h"
Node* P::tryParse(TokStreamer* st) {
    int save = st->getIndex();
    Node* P_Node;
    P1& P1_Parser = P1::getInstance();
    P2& P2_Parser = P2::getInstance();
    P3& P3_Parser = P3::getInstance();
    if (P_Node = P1_Parser.tryParse(st)) {
        //maybe Node::createNode
        return P_Node;
    }
    
    st->setIndex(save);
    if (P_Node = P2_Parser.tryParse(st)) {
        //maybe Node::createNode
        return P_Node;
    }

    st->setIndex(save);
    if (P_Node = P3_Parser.tryParse(st)) {
        //maybe Node::createNode
        return P_Node;
    }

	st->setIndex(save);
    return nullptr;
};