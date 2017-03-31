#ifndef F_HEADER
#define F_HEADER
#include "../../../Base/BaseGrammar.h"
#include "F1.h"


using namespace BaseGrammar;

namespace F {
    
    Node* tryParse(TokStreamer* st);
};

#endif