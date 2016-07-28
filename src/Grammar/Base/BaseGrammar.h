#ifndef BaseGrammar_H
#define BaseGrammar_H
#include <iostream>
#include "../../Parsing/TokStreamer.h"
#include "../../Base/Node.h"
#include "../../Base/Tok.h"
#include <string>


class BaseGrammar {
    public:
        virtual Node* tryParse(TokStreamer* st) {};
        static BaseGrammar& instance;
        bool accept(Tok& tok, tokType t);
        bool expect(Tok& tok, tokType t);
        void error(std::string errormsg);
        bool termByType(tokType type, TokStreamer* ts);
        bool termByValue(std::string value, TokStreamer* ts);
};




    /*if(tryParse(Program)) {
        cool
    }
    
    def tryParse(Statement[] ):
        while(tryParse(Statement)) {
            sababa
        }
    
    def parseStatement(statement):
        BaseGrammar s = [, STMT2, STMT3]
        for gramm in s:
            if gramm.matches(statement) {
                return 
            }
    
    def tryParse(Statement):
        [PRINT_STATEMENT, READ_STATEMENT, ]
    
    
        B(),]
        
        
    -----Parser----
    if(Program.tryParse(st)) {
        run
    }
    
    
    
    ----Program.tryParse(st)----
    while(Statement.tryParse(st)) {
        
    }
    
    ----Statement.tryParse(st)----
    
    int i = generate_number();
    
    //STMT50 = TYPE ID '=' EXPRESSION';'
    
    POSSIBLE_STATEMENTs = 
    for stmt in POSSIBLE_STATEMENTs:
        if stmt.tryParse(st):
            node stuff
            return true
    
    
    
    tryparse(C())
    tryparse(B()) != null {
        interpret(returned)
    }
<<<<<<< HEAD
    tryparse(Expression())*/
=======
    tryparse(E())*/
>>>>>>> af25e5201f487a98dd50ca74b3091d9d21b2ffe9
#endif
