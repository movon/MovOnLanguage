#ifndef LTwo1_HEADER
#define LTwo1_HEADER

#include "../../../Base/BaseGrammar.h"

class LTwo1: public BaseGrammar {
    
public:
    Node* tryParse(TokStreamer* ts);
    static LTwo1& getInstance() {
        static LTwo1 instance; // Guaranteed to be destroyed. // Instantiated on first use.
        return instance;
    }
        
        
    // Correct way to declare a lazy evaluated with guaranteed deletion singleton
    LTwo1(LTwo1 const&)               = delete;
    void operator=(LTwo1 const&)  = delete;


private:
    LTwo1() {};                   // Constructor? (the {} brackets) are needed here.
};
#endif