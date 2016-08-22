#include "Expression.h"


Node* E::tryParse(TokStreamer* ts) {
    int save = ts->getIndex();
    Node* (*e_grammars[])(TokStreamer*) = {E1::tryParse, E2::tryParse, E3::tryParse, E4::tryParse, E5::tryParse};

    Node* e = nullptr;

    for(auto grammar : e_grammars) {
        e = grammar(ts);
        if (e != nullptr) {
            return e;
        } else {
            ts->setIndex(save);
        }
    }
    
    return nullptr;
}