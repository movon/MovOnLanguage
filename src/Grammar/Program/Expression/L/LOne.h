#ifndef LOne_HEADER
#define LOne_HEADER

#include "../../../Base/BaseGrammar.h"
#include "LOne1.h"
#include "LOne2.h"

class LOne : public BaseGrammar {
public:
    Node* tryParse(TokStreamer* st);
    static LOne& getInstance() {
        static LOne instance; // Guaranteed to be destroyed. // Instantiated on first use.
        return instance;
    }
    
    
    // Correct way to declare a lazy evaluated with guaranteed deletion singleton
    LOne(LOne const&)               = delete;
    void operator=(LOne const&)  = delete;


private:
    LOne() {};                   // Constructor? (the {} brackets) are needed here.
};
#endif
