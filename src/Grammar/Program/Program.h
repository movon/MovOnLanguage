#ifndef PROGRAM_HEADER
#define PROGRAM_HEADER

#include "../Base/BaseGrammar.h"
#include "E/E.h"

class Program: public BaseGrammar {
public:
    Node* tryParse(TokStreamer* ts);
    static Program& getInstance() {
        static Program instance; // Guaranteed to be destroyed. // Instantiated on first use.
        return instance;
    }
    
    
    // Correct way to declare a lazy evaluated with guaranteed deletion singleton
    Program(Program const&)               = delete;
    void operator=(Program const&)  = delete;


private:
    Program() {};                   // Constructor? (the {} brackets) are needed here.
};
#endif
