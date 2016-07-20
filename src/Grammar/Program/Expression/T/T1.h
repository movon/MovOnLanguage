#include "../../../Base/BaseGrammar"
class T1 : public BaseGrammar {
    public:
        Node* tryParse(TokStreamer* st);
};