#include "E.h"


Node* E::tryParse(TokStreamer* ts) {
    int save = ts->getIndex();
    
    std::vector<BaseGrammar *> e_grammars;

    e_grammars.push_back(&E1::getInstance());
    e_grammars.push_back(&E2::getInstance());
    e_grammars.push_back(&E3::getInstance());
    e_grammars.push_back(&E4::getInstance());
    e_grammars.push_back(&E5::getInstance());
    
    Node* e = nullptr;

    for(auto grammar : e_grammars) {
        e = grammar->tryParse(ts);
        if (e != nullptr) {
            return e;
        } else {
            ts->setIndex(save);
        }
    }
    
    return nullptr;
}