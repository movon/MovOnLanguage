#ifndef PROGRAM_HEADER
#define PROGRAM_HEADER

#include "../Base/BaseGrammar.h"
<<<<<<< HEAD
#include "Expression/Expression.h"
=======
#include "E/E.h"
>>>>>>> af25e5201f487a98dd50ca74b3091d9d21b2ffe9

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
