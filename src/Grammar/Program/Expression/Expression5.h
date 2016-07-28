#ifndef E5_HEADER
#define E5_HEADER

#include "../../Base/BaseGrammar.h"
#include "Expression.h"
class E5: public BaseGrammar {
public:
    Node* tryParse(TokStreamer* st);
    static E5& getInstance() {
        static E5 instance; // Guaranteed to be destroyed. // Instantiated on first use.
        return instance;
    }
    
    
    // Correct way to declare a lazy evaluated with guaranteed deletion singleton
    E5(E5 const&)               = delete;
    void operator=(E5 const&)  = delete;


private:
    E5() {};                   // Constructor? (the {} brackets) are needed here.
};
#endif
