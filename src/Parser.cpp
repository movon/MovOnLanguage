#include "Parser.h"
#include "TokStreamer.h"
#include "Tok.h"
 
void error(std::string errormsg, Tok& t) {
    //needs implementing
    //in the error class most likely
}
 
bool Parser::accept(Tok& tok, tokType& t) {
    return tok.type == t;
}
 
bool Parser::expect(Tok& tok, tokType& t) {
    if (accept(tok, t)) {
        return true;
    }
    error("Unexpected symbol", tok);
    return false;
}
 
//I don't think that defining the vars in the header works because it didn't work for the lexer
void Parser::run(std::std::vector<Tok> toks) {// need to edit this
        TokStreamer* streamer = new TokStreamer(toks, -1)
        Tok currentTok = streamer->getNextToken();
        while (currentTok.type != tokType::ENDOFINPUT) {
            switch(currentTok.type){
            case keyword:
                handleKeywords(currentTok);
               
            }
        currentTok = streamer->getNextToken();
        }
 
}
 
void handleKeywords(Tok currentTok) {
        switch(currentTok.content){
                case INT:
                        handle INT;
                case print:
               
        }
       
}
 
void Parser::createNode(Node* parent, NodeType nodeType, std::vector<Tok> tokens){
    Node* node = new Node(parent, nodeType, tokens);
    parent->children.push_back(node);
   
}