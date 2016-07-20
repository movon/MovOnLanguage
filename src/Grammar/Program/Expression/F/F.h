#include "../../../Base/BaseGrammar"
class F : public BaseGrammar {
    public:
        Node* tryParse(TokStreamer* st);
}