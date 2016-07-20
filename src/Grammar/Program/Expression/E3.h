#include "../../Base/BaseGrammar.h"

class E3: public BaseGrammar {
public:
    Node* tryParse(TokStreamer* st);
};