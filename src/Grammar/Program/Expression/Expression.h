#ifndef E_HEADER
#define E_HEADER

#include "../../Base/BaseGrammar.h"
#include "Expression1.h"
#include "Expression2.h"
#include "Expression3.h"
#include "Expression4.h"
#include "Expression5.h"

namespace E {

    Node* tryParse(TokStreamer* st);
};

#endif
