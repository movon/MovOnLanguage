#ifndef LTwo2_HEADER
#define LTwo2_HEADER

#include "../../../Base/BaseGrammar.h"

class LTwo2: public BaseGrammar {
    
public:
    Node* tryParse(TokStreamer* ts);
    static LTwo2& getInstance() {
        static LTwo2 instance; // Guaranteed to be destroyed. // Instantiated on first use.
        return instance;
    }
        
        
    // Correct way to declare a lazy evaluated with guaranteed deletion singleton
    LTwo2(LTwo2 const&)               = delete;
    void operator=(LTwo2 const&)  = delete;


private:
    LTwo2() {};                   // Constructor? (the {} brackets) are needed here.
};
#endif