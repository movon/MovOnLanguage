#include "T1.h"

Node* T1::merge_extra_term(Node* T_Father, Node* newT) {
    if(T_Father->numChildren() == 1) {
        T_Father->addChild(newT->getChild(0));
        T_Father->addChild(newT->getChild(1));
        newT->disownAllChildren();
        delete newT;
        return T_Father;
    } else {
        newT->addChild(T_Father);
        return newT;
    }
}

Node* T1::findF(TokStreamer* st) {
    Job LTwoParser(LTwo::tryParse, st);
    Job FParser(F::tryParse, st);
    LTwoParser.executeTask();
    if(LTwoParser.succeeded()) {
        FParser.executeTask();
        if(FParser.succeeded()) {
            Node* T = Node::createNode(nullptr, NodeType::E);
            T->addChild(LTwoParser.getResult());
            T->addChild(FParser.getResult());
            return T;
        }
    }

    return nullptr;
}

Node* T1::chainFExecute(TokStreamer* st) {
    Job findFParser(T1::findF, st);
    Node* T = Node::createNode(nullptr, NodeType::E);
    Job chainF(&T1::chainFExecute, st);
    findFParser.onSuccess(&chainF, T1::merge_extra_term);
}

Node* T1::addF_to_T(TokStreamer* st) {
    Node* T = Node::createNode(nullptr, NodeType::E);
    Job FParser(F::tryParse, st);
    FParser.executeTask();
    if(FParser.succeeded()) {
        T->addChild(FParser.getResult());
        return T;
    }
    return nullptr;
}

Node* T1::tryParse(TokStreamer* st) {
    Job FParser(&T1::addF_to_T, st);
    Job chainF(&T1::chainFExecute, st);
    FParser.onSuccess(&chainF, &T1::merge_extra_term);
    FParser.executeTask();
    if (FParser.succeeded()) {
		return FParser.getResult();
    }
    
    return nullptr;
}