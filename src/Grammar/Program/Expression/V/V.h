#ifndef V_HEADER
#define V_HEADER
#include "../../../Base/BaseGrammar.h"
#include "V1.h"
#include "V2.h"
#include "V3.h"


namespace V {

    Node* tryParse(TokStreamer* st);
};

#endif