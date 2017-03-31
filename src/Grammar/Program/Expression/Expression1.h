#ifndef E1_HEADER
#define E1_HEADER

#include "../../Base/BaseGrammar.h"
#include "T/T.h"
#include "L/LOne.h"
#include "Expression.h"

using namespace BaseGrammar;

namespace E1 {

    Node* tryParse(TokStreamer* st);
};

#endif
