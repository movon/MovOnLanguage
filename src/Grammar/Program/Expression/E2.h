#include "../../Base/BaseGrammar.h"

class E2: public BaseGrammar {
public:
    Node* tryParse(TokStreamer* st);
};