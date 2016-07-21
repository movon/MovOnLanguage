#ifndef F1_HEADER
#define F1_HEADER
#include "../../../Base/BaseGrammar.h"
#include "../P/P.h"
#include "F.h"

class F1 : public BaseGrammar {
    public:
        Node* tryParse(TokStreamer* st);
        static F1& getInstance() {
            static F1 instance; // Guaranteed to be destroyed. // Instantiated on first use.
            return instance;
        }
        
        
        // Correct way to declare a lazy evaluated with guaranteed deletion singleton
        F1(F1 const&)               = delete;
        void operator=(F1 const&)  = delete;


    private:
        F1() {};                   // Constructor? (the {} brackets) are needed here.

};
#endif