#ifndef P3_HEADER
#define P3_HEADER

#include "../../../Base/BaseGrammar.h"
#include "../T/T1.h"
#include "../T/T.h"


using namespace BaseGrammar;

namespace P3 {
    
    Node* tryParse(TokStreamer* st);
};

#endif