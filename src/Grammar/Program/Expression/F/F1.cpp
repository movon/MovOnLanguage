#include "F1.h"

Node* F1::addP_to_F(TokStreamer* st) {
    Job PParser(P::tryParse, st);
    PParser.executeTask();
    if(PParser.suceeded()) {
        Node* F_Node = Node::createNode(nullptr, NodeType::E);
        F_Node->addChild(PParser.getResult());
        return F_Node;
    }

    return nullptr;
}

Node* F1::chainPExecute(TokStreamer* st) {
    Job PParser(&P::tryParse, st);
    Job FParser(&F::tryParse, st);
    if (termByValue("^", st)) {
        FParser.executeTask();
        if(FParser.suceeded()) {
            Node* f = Node::createNode(nullptr, NodeType::E);
            Node::createNode(f, NodeType::EXPO, Tok("^", tokType::OPERATOR));
            f->addChild(FParser.getResult());
            return f;
        }
    }

    return nullptr;
}

Node* F1::merge_extra_term(Node* F_Father, Node* newF) {
    F_Father->addChild(newF->getChild(0));
    F_Father->addChild(newF->getChild(1));
    newF->disownAllChildren();
    delete newF;
    return F_Father;
}

Node* F1::tryParse(TokStreamer* st) {
    Job PParser(&F1::addP_to_F, st);
    Job chainP(&F1::chainPExecute, st);
    PParser.onSuccess(&chainP, &F1::merge_extra_term);
    PParser.executeTask();
    if(PParser.suceeded()) {
        return PParser.getResult();
    }

    return nullptr;
}