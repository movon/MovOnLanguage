#ifndef E3_HEADER
#define E3_HEADER

#include "../../Base/BaseGrammar.h"
#include "Expression.h"
class E3: public BaseGrammar {
public:
    Node* tryParse(TokStreamer* st);
    static E3& getInstance() {
        static E3 instance; // Guaranteed to be destroyed. // Instantiated on first use.
        return instance;
    }
    
    
    // Correct way to declare a lazy evaluated with guaranteed deletion singleton
    E3(E3 const&)               = delete;
    void operator=(E3 const&)  = delete;


private:
    E3() {};                   // Constructor? (the {} brackets) are needed here.
};
#endif
