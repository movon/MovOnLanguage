#ifndef P3_HEADER
#define P3_HEADER
#include "../../../Base/BaseGrammar.h"
#include "../T/T1.h"
#include "../T/T.h"
class P3 : public BaseGrammar {
    public:
        Node* tryParse(TokStreamer* st);
        static P3& getInstance() {
            static P3 instance; // Guaranteed to be destroyed. // Instantiated on first use.
            return instance;
        }
        
        
        // Correct way to declare a lazy evaluated with guaranteed deletion singleton
        P3(P3 const&)               = delete;
        void operator=(P3 const&)  = delete;


    private:
        P3() {};                   // Constructor? (the {} brackets) are needed here.

};
#endif