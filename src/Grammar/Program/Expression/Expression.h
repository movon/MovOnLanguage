#ifndef E_HEADER
#define E_HEADER

#include "../../Base/BaseGrammar.h"
#include "Expression1.h"
#include "Expression2.h"
#include "Expression3.h"
#include "Expression4.h"
#include "Expression5.h"

class E: public BaseGrammar {
public:
    Node* tryParse(TokStreamer* st);
    static E& getInstance() {
        static E instance; // Guaranteed to be destroyed. // Instantiated on first use.
        return instance;
    }
    
    
    // Correct way to declare a lazy evaluated with guaranteed deletion singleton
    E(E const&)               = delete;
    void operator=(E const&)  = delete;


private:
    E() {};                   // Constructor? (the {} brackets) are needed here.
};
#endif
