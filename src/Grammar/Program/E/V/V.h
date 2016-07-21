#ifndef V_HEADER
#define V_HEADER
#include "../../../Base/BaseGrammar.h"
#include "V1.h"
#include "V2.h"
#include "V3.h"


class V: public BaseGrammar {
public:
    Node* tryParse(TokStreamer* st);
    static V& getInstance() {
        static V instance; // Guaranteed to be destroyed. // Instantiated on first use.
        return instance;
    }
    
    
    // Correct way to declare a lazy evaluated with guaranteed deletion singleton
    V(V const&)               = delete;
    void operator=(V const&)  = delete;


private:
    V() {};                   // Constructor? (the {} brackets) are needed here.
};
#endif