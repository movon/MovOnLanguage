#ifndef LOne_HEADER
#define LOne_HEADER

#include "../../../Base/BaseGrammar.h"
#include "LOne1.h"
#include "LOne2.h"


using namespace BaseGrammar;

namespace LOne {

    Node* tryParse(TokStreamer* st);
};

#endif
