#ifndef PROGRAM_HEADER
#define PROGRAM_HEADER

#include "../Base/BaseGrammar.h"


class BaseGrammar: public BaseGrammar {
public:
    Node* tryParse(TokStreamer* st);
    static BaseGrammar& getInstance() {
        static BaseGrammar instance; // Guaranteed to be destroyed. // Instantiated on first use.
        return instance;
    }
    
    
    // Correct way to declare a lazy evaluated with guaranteed deletion singleton
    BaseGrammar(BaseGrammar const&)               = delete;
    void operator=(BaseGrammar const&)  = delete;


private:
    BaseGrammar() {};                   // Constructor? (the {} brackets) are needed here.
};
#endif
