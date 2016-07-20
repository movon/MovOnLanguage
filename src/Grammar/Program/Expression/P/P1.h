#include "../../../Base/BaseGrammar"
class P1 : public BaseGrammar {
    public:
        Node* tryParse(TokStreamer* st);
};