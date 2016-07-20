#include "../../../Base/BaseGrammar.h"
class P : public BaseGrammar {
    public:
        Node* tryParse(TokStreamer* st);
}