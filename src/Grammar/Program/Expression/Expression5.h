#ifndef E5_HEADER
#define E5_HEADER

#include "../../Base/BaseGrammar.h"
#include "Expression.h"


using namespace BaseGrammar;

namespace E5 {

    Node* tryParse(TokStreamer* st);
};

#endif
