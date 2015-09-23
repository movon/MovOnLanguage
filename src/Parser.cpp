#include "Parser.h"
//I don't think that defining the vars in the header works because it didn't work for the lexer
void Parser::run(){// need to edit this 
    toks = Lexer::getTokens();
    
    for(int i = 0;i < toks.size();i++ ){
        auto currentTokenType = toks[i].type;
        if(currentTokenType == tokType::FUNCTION){// The function token type only appears in function callings we didn't make function defenitions yet
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

