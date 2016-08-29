#ifndef PROGRAM_HEADER
#define PROGRAM_HEADER

#include "../Base/BaseGrammar.h"
//#include "Expression/Expression.h"
#include "FunctionGrammar/FunctionDef.h"

namespace Program {

    Node* tryParse(TokStreamer* ts);
};

#endif
