#ifndef T1_HEADER
#define T1_HEADER

#include "../../../Base/BaseGrammar.h"
#include "../F/F.h"
#include "../L/LTwo.h"


using namespace BaseGrammar;

namespace T1 {
    
    Node* tryParse(TokStreamer* ts);

    Node *chainFExecute(TokStreamer *st);

    Node *addF_to_T(TokStreamer* st);

    Node* merge_extra_term(Node* T_Father, Node* newT);

    Node *findF(TokStreamer *st);
};

#endif
