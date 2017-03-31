#ifndef E4_HEADER
#define E4_HEADER

#include "../../Base/BaseGrammar.h"
#include "Expression.h"


using namespace BaseGrammar;

namespace E4 {

        Node* tryParse(TokStreamer* ts);
};

#endif
