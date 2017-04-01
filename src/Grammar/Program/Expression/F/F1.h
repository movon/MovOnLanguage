#ifndef F1_HEADER
#define F1_HEADER
#include "../../../Base/BaseGrammar.h"
#include "../P/P.h"
#include "F.h"


using namespace BaseGrammar;

namespace F1 {
    Node* tryParse(TokStreamer* st);
    Node *addP_to_F(TokStreamer *st);
    Node *chainPExecute(TokStreamer *st);
    Node *merge_extra_term(Node *F_Father, Node *newF);
};

#endif