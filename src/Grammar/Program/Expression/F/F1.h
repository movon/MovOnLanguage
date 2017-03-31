#ifndef F1_HEADER
#define F1_HEADER
#include "../../../Base/BaseGrammar.h"
#include "../P/P.h"
#include "F.h"


using namespace BaseGrammar;

namespace F1 {
    
    Node* tryParse(TokStreamer* st);
};

#endif