#include "../../Base/BaseGrammar.h"

class E5: public BaseGrammar {
public:
    Node* tryParse(TokStreamer* st);
};