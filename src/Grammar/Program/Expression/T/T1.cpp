#include "T1.h"

Node* T1::merge_extra_term(Node* LTwo_Node, Node*)

Node* T1::addTExecute(TokStreamer* st) {
    Job LTwoParser(LTwo::tryParse, st);

    LTwoParser.onSuccess(&Job(T1::addTExecute, st), &T1::merge_extra_term);
    while (LTwo_Node = LTwo::tryParse(st)) {
        if (T->numChildren() == 1){
            T->addChild(LTwo_Node);
            if (F_Node = F::tryParse(st)){
                T->addChild(F_Node);
            }
            else{
                error("expected a term after \"*\" or \"/\" ");
            }
        }
        else{
            Node* newE = Node::createNode(nullptr, NodeType::E);
            newE->addChild(T);
            Node* temp = newE;
            newE = T;
            T = temp;
            T->addChild(LTwo_Node);
            if (F_Node = F::tryParse(st)) {
                T->addChild(F_Node);
            }
            else{
                error("expected a term after \"*\" or \"/\" ");
            }
        }
    }
}

Node* T1::merge_F_T(Node* F, Node* T) {
    T->addChild(F);
    return T;
}

Node* T1::tryParse(TokStreamer* st) {
    Job FParser(F::tryParse, st);
    Job LTwoParser(LTwo::tryParse, st);
    Job TParser(T::tryParse, st);
    Job addT(addTExecute, st);
    FParser.onSuccess(&TParser, &T1::merge_F_T);
    FParser.onSuccess(&addT, );
    Node* T, result;
    if (F_Node) {

		return T;
    }
    
    return nullptr;
}