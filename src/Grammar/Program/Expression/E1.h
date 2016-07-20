#include "../../Base/BaseGrammar.h"
#include "T/T.h"

class E1: public BaseGrammar {
public:
    Node* tryParse(TokStreamer* st);
};