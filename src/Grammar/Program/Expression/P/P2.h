#include "../../../Base/BaseGrammar"
class P2 : public BaseGrammar {
    public:
        Node* tryParse(TokStreamer* st);
};