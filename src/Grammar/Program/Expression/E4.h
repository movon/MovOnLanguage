#include "../../Base/BaseGrammar.h"

class E4: public BaseGrammar {
public:
    Node* tryParse(TokStreamer* st);
};