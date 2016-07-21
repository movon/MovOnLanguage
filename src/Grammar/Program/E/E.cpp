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
    int index = 0;
    
    for(auto grammar : e_grammars) {
        index++;
        e = grammar->tryParse(ts);
        if (e != nullptr) {
            std::cout << "OMG I FOUND A FITTING GRAMMAR, node numChildren" << e->numChildren() << std::endl;
            std::cout << "children of son:" << e->getChild(0)->numChildren() << std::endl;
            std::cout << "E" << index << " matches." << std::endl;
            return e;
        } else {
            ts->setIndex(save);
        }
    }
    
    return nullptr;
}