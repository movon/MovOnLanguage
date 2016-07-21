#ifndef P2_HEADER
#define P2_HEADER
#include "../../../Base/BaseGrammar.h"
#include "../E.h"
class P2 : public BaseGrammar {
    public:
        Node* tryParse(TokStreamer* st);
        static P2& getInstance() {
            static P2 instance; // Guaranteed to be destroyed. // Instantiated on first use.
            return instance;
        }
        
        
        // Correct way to declare a lazy evaluated with guaranteed deletion singleton
        P2(P2 const&)               = delete;
        void operator=(P2 const&)  = delete;


    private:
        P2() {};                   // Constructor? (the {} brackets) are needed here.

};
#endif
