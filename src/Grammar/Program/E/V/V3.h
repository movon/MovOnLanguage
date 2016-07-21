#include "../../../Base/BaseGrammar.h"

class V3: public BaseGrammar {
public:
    Node* tryParse(TokStreamer* st);
    static V3& getInstance() {
        static V3 instance; // Guaranteed to be destroyed. // Instantiated on first use.
        return instance;
    }
    
    
    // Correct way to declare a lazy evaluated with guaranteed deletion singleton
    V3(V3 const&)               = delete;
    void operator=(V3 const&)  = delete;


private:
    V3() {};                   // Constructor? (the {} brackets) are needed here.
};