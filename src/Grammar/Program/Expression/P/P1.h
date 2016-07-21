#ifndef P1_HEADER
#define P1_HEADER

#include "../../../Base/BaseGrammar.h"
#include "../V/V.h"

class P1 : public BaseGrammar {
    public:
        Node* tryParse(TokStreamer* st);
        static P1& getInstance() {
            static P1 instance; // Guaranteed to be destroyed. // Instantiated on first use.
            return instance;
        }
        
        
        // Correct way to declare a lazy evaluated with guaranteed deletion singleton
        P1(P1 const&)               = delete;
        void operator=(P1 const&)  = delete;


    private:
        P1() {};                   // Constructor? (the {} brackets) are needed here.

};
#endif
