#ifndef P2_HEADER
#define P2_HEADER

#include "../../../Base/BaseGrammar.h"
#include "../Expression.h"


using namespace BaseGrammar;

namespace P2 {
    
    Node* tryParse(TokStreamer* st);
};

#endif
