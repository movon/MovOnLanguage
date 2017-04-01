#ifndef E1_HEADER
#define E1_HEADER

#include "../../Base/BaseGrammar.h"
#include "T/T.h"
#include "L/LOne.h"
#include "Expression.h"
#include "../../../Parsing/Flow/Job.h"

using namespace BaseGrammar;

namespace E1 {
    Node* tryParse(TokStreamer* st);
    Node* addL1(Job TParser, Node *E, TokStreamer *st);
};

#endif
