#ifndef E4_HEADER
#define E4_HEADER

#include "../../Base/BaseGrammar.h"
#include "Expression.h"
class E4: public BaseGrammar {
    public:
        Node* tryParse(TokStreamer* ts);
        static E4& getInstance() {
            static E4 instance; // Guaranteed to be destroyed. // Instantiated on first use.
            return instance;
        }
        
        
        // Correct way to declare a lazy evaluated with guaranteed deletion singleton
        E4(E4 const&)               = delete;
        void operator=(E4 const&)  = delete;


    private:
        E4() {};                   // Constructor? (the {} brackets) are needed here.
};
#endif
