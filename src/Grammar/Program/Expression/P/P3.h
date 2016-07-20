#include "../../../Base/BaseGrammar"
class P3 : public BaseGrammar {
    public:
        Node* tryParse(TokStreamer* st);
};