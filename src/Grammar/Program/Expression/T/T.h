#ifndef T_HEADER
#define T_HEADER

#include "../../../Base/BaseGrammar.h"
#include "T1.h"
class T : public BaseGrammar {
    public:
        Node* tryParse(TokStreamer* st);
        static T& getInstance() {
            static T instance; // Guaranteed to be destroyed. // Instantiated on first use.
            return instance;
        }
        
        
        // Correct way to declare a lazy evaluated with guaranteed deletion singleton
        T(T const&)               = delete;
        void operator=(T const&)  = delete;


    private:
        T() {};                   // Constructor? (the {} brackets) are needed here.
};
#endif
