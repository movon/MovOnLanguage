#include "../../../Base/BaseGrammar.h"

class V1: public BaseGrammar {
public:
    Node* tryParse(TokStreamer* st);
    static V1& getInstance() {
        static V1 instance; // Guaranteed to be destroyed. // Instantiated on first use.
        return instance;
    }
    
    
    // Correct way to declare a lazy evaluated with guaranteed deletion singleton
    V1(V1 const&)               = delete;
    void operator=(V1 const&)  = delete;


private:
    V1() {};                   // Constructor? (the {} brackets) are needed here.
};