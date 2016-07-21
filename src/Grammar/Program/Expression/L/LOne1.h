#ifndef LOne1_HEADER
#define LOne1_HEADER

#include "../../../Base/BaseGrammar.h"

class LOne1 : public BaseGrammar {
    public:
        Node* tryParse(TokStreamer* st);
        static LOne1& getInstance() {
            static LOne1 instance; // Guaranteed to be destroyed. // Instantiated on first use.
            return instance;
        }
        
        
        // Correct way to declare a lazy evaluated with guaranteed deletion singleton
        LOne1(LOne1 const&)               = delete;
        void operator=(LOne1 const&)  = delete;


    private:
        LOne1() {};                   // Constructor? (the {} brackets) are needed here.
};
#endif
