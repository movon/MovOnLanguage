#include "parser.h"

void Parser::run(){// need to edit this 
    toks = Lexer::getTokens();
    
    for(int i = 0;i < toks.size();i++ ){
        auto currentTokenType = toks[i].type;
        if(currentTokenType == tokType::FUNCTION){
            createParentNode(toks[i-1].content, NodeType::FUNCTION); // need to add checking for this. eg instead of Function() we have () without a string before
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

void Parser::createNode(Node* parent, NodeType nodeType, std::vector<Tok> tokens){
    Node* node = new Node(parent, nodeType, tokens);
    parent->children.push_back(node);
    
}

void Parser::createParentNode(std::string Name, NodeType nodeType){
    
}

void Parser::createParentNode(std::string name){
    ParentNode* parentNode = new ParentNode(name);
}