#ifndef F_HEADER
#define F_HEADER
#include "../../../Base/BaseGrammar.h"
#include "F1.h"

class F : public BaseGrammar {
    public:
        Node* tryParse(TokStreamer* st);
        static F& getInstance() {
            static F instance; // Guaranteed to be destroyed. // Instantiated on first use.
            return instance;
        }
        
        
        // Correct way to declare a lazy evaluated with guaranteed deletion singleton
        F(F const&)               = delete;
        void operator=(F const&)  = delete;


    private:
        F() {};                   // Constructor? (the {} brackets) are needed here.
};
#endif