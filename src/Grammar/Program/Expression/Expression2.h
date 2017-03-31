#ifndef E2_HEADER
#define E2_HEADER

#include "../../Base/BaseGrammar.h"
#include "Expression.h"

using namespace BaseGrammar;

namespace E2 {

    Node* tryParse(TokStreamer* st);
};

#endif
