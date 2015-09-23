#include "Parser.h"

void error(std::string errormsg, tokType& t) {
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
    error("Unexpected symbol", t);
    return false;
}

//I don't think that defining the vars in the header works because it didn't work for the lexer
void Parser::run(){// need to edit this 
    toks = Lexer::getTokens();
    
    for(int i = 0;i < toks.size();i++ ){
        tokType currentTokenType = toks[i].type;
        if(currentTokenType == tokType::FUNCTIONDEF){
            if(prevParent != nullptr){
                createNode(prevParent, NodeType::FUNCTION, currentStatement); // need to add checking for this. eg instead of Function() we have () without a string before
            }
            currentStatement.clear();
        }
        else if(currentTokenType != tokType::DELIMITER || currentTokenType != tokType::CLOSINGPARAN){
            currentStatement.push_back(toks[i]);
            prevStatement = currentStatement;// Shouldn't this be in the else section?
            
        }
        else{
            currentStatement.push_back(toks[i]);
            
        }
    }    
    }

void Parser::createNode(Node* parent, NodeType nodeType, std::vector<Tok> tokens){
    Node* node = new Node(parent, nodeType, tokens);
    parent->children.push_back(node);
    
}

