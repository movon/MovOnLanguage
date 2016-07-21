#ifndef P_HEADER
#define P_HEADER
#include "../../../Base/BaseGrammar.h"
#include "P1.h"
#include "P2.h"
#include "P3.h"
class P : public BaseGrammar {
    public:
        Node* tryParse(TokStreamer* st);
        static P& getInstance() {
            static P instance; // Guaranteed to be destroyed. // Instantiated on first use.
            return instance;
        }
        
        
        // Correct way to declare a lazy evaluated with guaranteed deletion singleton
        P(P const&)               = delete;
        void operator=(P const&)  = delete;


    private:
        P() {};                   // Constructor? (the {} brackets) are needed here.
};
#endif
