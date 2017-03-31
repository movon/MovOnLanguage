#ifndef T1_HEADER
#define T1_HEADER

#include "../../../Base/BaseGrammar.h"
#include "../F/F.h"
#include "../L/LTwo.h"


using namespace BaseGrammar;

namespace T1 {
    
    Node* tryParse(TokStreamer* ts);
};

#endif
