#ifndef P_HEADER
#define P_HEADER

#include "../../../Base/BaseGrammar.h"
#include "P1.h"
#include "P2.h"
#include "P3.h"
#include "../../../../Parsing/Flow/Pipeline.h"
#include <vector>

namespace P {
    
    Node* tryParse(TokStreamer* st);
};

#endif
