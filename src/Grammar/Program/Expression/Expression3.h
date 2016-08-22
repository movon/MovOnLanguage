#ifndef E3_HEADER
#define E3_HEADER

#include "../../Base/BaseGrammar.h"
#include "Expression.h"


using namespace BaseGrammar;

namespace E3 {

    Node* tryParse(TokStreamer* st);
};

#endif
