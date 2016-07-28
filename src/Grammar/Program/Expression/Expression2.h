#ifndef E2_HEADER
#define E2_HEADER

#include "../../Base/BaseGrammar.h"
#include "Expression.h"

class E2: public BaseGrammar {
public:
    Node* tryParse(TokStreamer* st);
    static E2& getInstance() {
        static E2 instance; // Guaranteed to be destroyed. // Instantiated on first use.
        return instance;
    }
    
    
    // Correct way to declare a lazy evaluated with guaranteed deletion singleton
    E2(E2 const&)               = delete;
    void operator=(E2 const&)  = delete;


private:
    E2() {};                   // Constructor? (the {} brackets) are needed here.
};
#endif
