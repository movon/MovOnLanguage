#ifndef LOne2_HEADER
#define LOne2_HEADER

#include "../../../Base/BaseGrammar.h"
class LOne2 : public BaseGrammar {
    public:
        Node* tryParse(TokStreamer* st);
        static LOne2& getInstance() {
            static LOne2 instance; // Guaranteed to be destroyed. // Instantiated on first use.
            return instance;
        }
        
        
        // Correct way to declare a lazy evaluated with guaranteed deletion singleton
        LOne2(LOne2 const&)               = delete;
        void operator=(LOne2 const&)  = delete;


    private:
        LOne2() {};                   // Constructor? (the {} brackets) are needed here.
};
#endif
