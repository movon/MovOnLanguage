#ifndef STATEMENT_H
#define STATEMENT_H


#include "../../Base/BaseGrammar.h"
#include "FunctionDef.h"
#include "FuncCall.h"

namespace Statement{
	Node* tryParse(TokStreamer* st);
}


#endif