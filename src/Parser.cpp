#include "Parser.h"
 
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
void Parser::run(std::vector<Tok> toks) {// need to edit this
        TokStreamer* streamer = new TokStreamer(toks, -1);
        prevParent = new ParentNode("Program");
        Tok currentTok = streamer->getNextToken();
        while (currentTok.type != tokType::ENDOFINPUT) {
            switch(currentTok.type) {
                case tokType::KEYWORD:
                    handleKeywords(currentTok, streamer);
                case tokType::TYPE:
                    handleTypes(currentTok, streamer);
            }
            currentTok = streamer->getNextToken();
        }
 
}
 
void Parser::handleKeywords(Tok currentTok, TokStreamer* streamer) {
        switch(currentTok.content){
            case print:
                Print(streamer);
        }
}

void Parser::Print(TokStreamer* streamer) {
    Tok next = streamer->peekNextTok();
    if (accept(next, tokType::STRING)) {
        createNode()
        streamer->advancePosition();
    }
    else if (accpet(next, tokType::IDENTIFIER)) {
        
        streamer->advancePosition();
    }
    else if (accept(next, tokType::INT)) {

        streamer->advancePosition();
    }
    else if (accept(next, tokType::FLOAT)) {

        streamer->advancePosition();
    }
    //else if expr

    expect(next, tokType::DELIMITER)
}

void Parser::handleTypes(Tok& currentTok, TokStreamer* streamer) {

}

void Parser::createNode(Node* parent, NodeType nodeType, std::vector<Tok> tokens){
    Node* node = new Node(parent, nodeType, tokens);
    parent->addChild(node);
   
}