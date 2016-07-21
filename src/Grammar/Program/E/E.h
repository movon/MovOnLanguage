#ifndef E_HEADER
#define E_HEADER

#include "../../Base/BaseGrammar.h"
#include "E1.h"
#include "E2.h"
#include "E3.h"
#include "E4.h"
#include "E5.h"

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
