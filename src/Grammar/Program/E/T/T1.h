#ifndef T1_HEADER
#define T1_HEADER

#include "../../../Base/BaseGrammar.h"
#include "../F/F.h"
#include "../L/LTwo.h"


class T1 : public BaseGrammar {
    public:
        Node* tryParse(TokStreamer* ts);
        static T1& getInstance() {
            static T1 instance; // Guaranteed to be destroyed. // Instantiated on first use.
            return instance;
        }
        
        
        // Correct way to declare a lazy evaluated with guaranteed deletion singleton
        T1(T1 const&)               = delete;
        void operator=(T1 const&)  = delete;


    private:
        T1() {};                   // Constructor? (the {} brackets) are needed here.
};
#endif
