#include "../../../Base/BaseGrammar.h"
class T : public BaseGrammar {
    public:
        static Node* tryParse(TokStreamer* st);
};