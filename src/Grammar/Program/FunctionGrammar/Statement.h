#ifndef STATEMENT_H
#define STATEMENT_H


#include "../../Base/BaseGrammar.h"
#include "FunctionDef.h"
#include "FuncCall.h"
#include "Keyword.h"
#include "Assignment.h"
#include "Flow.h"

namespace Statement{
	Node* tryParse(TokStreamer* st);
}


#endif
