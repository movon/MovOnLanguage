#ifndef V_HEADER
#define V_HEADER
#include "../../../Base/BaseGrammar.h"
#include "V1.h"
#include "V2.h"
#include "V3.h"
#include "../../../../Parsing/Flow/Job.h"
#include "../../../../Parsing/Flow/Pipeline.h"
#include <vector>


namespace V {

    Node* tryParse(TokStreamer* st);
};

#endif