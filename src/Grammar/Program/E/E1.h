#ifndef E1_HEADER
#define E1_HEADER

#include "../../Base/BaseGrammar.h"
#include "T/T.h"
#include "L/LOne.h"
#include "E.h"

class E1: public BaseGrammar {
public:
    Node* tryParse(TokStreamer* st);
    static E1& getInstance() {
        static E1 instance; // Guaranteed to be destroyed. // Instantiated on first use.
        return instance;
    }
    
    
    // Correct way to declare a lazy evaluated with guaranteed deletion singleton
    E1(E1 const&)               = delete;
    void operator=(E1 const&)  = delete;


private:
    E1() {};                   // Constructor? (the {} brackets) are needed here.
};
#endif
