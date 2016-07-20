#include "../../../Base/BaseGrammar"
class F1 : public BaseGrammar {
    public:
        Node* tryParse(TokStreamer* st);
}