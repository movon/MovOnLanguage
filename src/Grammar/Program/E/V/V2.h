#include "../../../Base/BaseGrammar.h"

class V2: public BaseGrammar {
public:
    Node* tryParse(TokStreamer* st);
    static V2& getInstance() {
        static V2 instance; // Guaranteed to be destroyed. // Instantiated on first use.
        return instance;
    }
    
    
    // Correct way to declare a lazy evaluated with guaranteed deletion singleton
    V2(V2 const&)               = delete;
    void operator=(V2 const&)  = delete;


private:
    V2() {};                   // Constructor? (the {} brackets) are needed here.
};