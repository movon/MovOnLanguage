#include "parser.h"

void Parser::run(){// need to edit this 
    auto toks = Lexer::getTokens();
    
    for(int i = 0;i < toks.size();i++ ){
        auto currentTokenType = toks[i].type;
        if(currentTokenType == tokType::FUNCTION){
            if(prevParent != nullptr){
                createNode(prevParent, NodeType::FUNCTION, currentStatement); // need to add checking for this. eg instead of Function() we have () without a string before
            }
            currentStatement.clear();
        }
        else if(currentTokenType != tokType::DELIMITER || currentTokenType != tokType::CLOSINGPARAN){
            currentStatement.push_back(toks[i]);
            prevStatement = currentStatement;
            
        }
        else{
            currentStatement.push_back(toks[i]);
            
        }
    }    
    }

Node* Parser::createNode(Node* parent, NodeType nodeType, std::vector<Tok> tokens){
    Node* node = new Node(parent, nodeType, tokens);
    parent->children.push_back(node);
    
}

