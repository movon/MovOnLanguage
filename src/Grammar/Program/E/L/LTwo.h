#ifndef LTwo_HEADER
#define LTwo_HEADER

#include "../../../Base/BaseGrammar.h"
#include "LTwo1.h"
#include "LTwo2.h"

class LTwo: public BaseGrammar {
    
public:
    Node* tryParse(TokStreamer* ts);
    static LTwo& getInstance() {
        static LTwo instance; // Guaranteed to be destroyed. // Instantiated on first use.
        return instance;
    }
        
        
    // Correct way to declare a lazy evaluated with guaranteed deletion singleton
    LTwo(LTwo const&)               = delete;
    void operator=(LTwo const&)  = delete;


private:
    LTwo() {};                   // Constructor? (the {} brackets) are needed here.
};
#endif