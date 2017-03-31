#ifndef LTwo_HEADER
#define LTwo_HEADER

#include "../../../Base/BaseGrammar.h"
#include "LTwo1.h"
#include "LTwo2.h"


using namespace BaseGrammar;

namespace LTwo {
    
    Node* tryParse(TokStreamer* ts);
};

#endif