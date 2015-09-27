#include "Parser.h"

ParentNode* currParent = nullptr;
Node* prevNode = nullptr;
std::vector<Tok> currentStatement;
std::vector<Tok> prevStatement;


void error(std::string errormsg, Tok& t) {
    //needs implementing
    //in the error class most likely
}
 
bool Parser::accept(Tok& tok, tokType t) {
    return tok.type == t;
}
 
bool Parser::expect(Tok& tok, tokType t) {
    if (accept(tok, t)) {
        return true;
    }
    error("Unexpected symbol", tok);
    return false;
}
 
//I don't think that defining the vars in the header works because it didn't work for the lexer
void Parser::run(std::vector<Tok> toks) {// need to edit this
        TokStreamer* streamer = new TokStreamer(toks, -1);
        currParent = new ParentNode("Program");
        Node* tempCurrParent;
        Tok currentTok = streamer->getNextToken();
        while (currentTok.type != tokType::ENDOFINPUT) {
            tempPrevParent = currParent;
            switch(currentTok.type) {
                case tokType::KEYWORD:
                    handleKeywords(currentTok, streamer);
                case tokType::TYPE:
                    handleTypes(currentTok, streamer);
            }
            currParent = tempCurrParent;
            currentTok = streamer->getNextToken();
        }
 
}
 
void Parser::handleKeywords(Tok currentTok, TokStreamer* streamer) {
        std::string con = currentTok.content;
        if (con == "print") {
            Print(currentTok, streamer);
        }
        //else if ...

}

void Parser::Print(Tok currentTok, TokStreamer* streamer) {
    Tok next = streamer->peekNextTok();
    std::vector<Tok> currNodeToks;
    currNodeToks.push_back(currentTok);//for debugging
    currParent = createNode(currParent, NodeType::FUNCTIONCALL, currNodeToks);
    currNodeToks.clear();

    if (accept(next, tokType::STRING)) {
        currNodeToks.push_back(next);
        createNode(currParent, NodeType::STRING, currNodeToks);
        currNodeToks.clear();
        streamer->advancePosition();
    }
    else if (accept(next, tokType::IDENTIFIER)) {
        currNodeToks.push_back(next)
        createNode(currParent, NodeType::IDENTIFIER, currNodeToks);
        currNodeToks.clear();
        streamer->advancePosition();
    }
    else if (accept(next, tokType::INT)) {
        currNodeToks.push_back(next)
        createNode(currParent, NodeType::INT, currNodeToks);
        currNodeToks.clear();
        streamer->advancePosition();
    }
    else if (accept(next, tokType::FLOAT)) {
        currNodeToks.push_back(next)
        createNode(currParent, NodeType::FLOAT, currNodeToks);
        currNodeToks.clear();
        streamer->advancePosition();
    }
    else {
        //error() or something along those lines
    }
    //else if expr
    next = streamer->getNextToken();
    expect(next, tokType::DELIMITER);
}

void Parser::handleTypes(Tok& currentTok, TokStreamer* streamer) {
    //Lexer::tokTypeToString
    std::vector<Tok> currNodeToks;
    currNodeToks.push_back(currentTok);
    Tok next = streamer->peekNextTok();
    expect(next, tokType::IDENTIFIER);
    streamer->advancePosition();
    currNodeToks.push_back(next);
    next = streamer->peekNextTok();
    if (accept(next, tokType::DELIMITER)) {
        createNode(currParent, NodeType::CREATION, currNodeToks);
        currNodeToks.clear();
    }
    else {
        expect(next, tokType::ASSIGNMENT);
        //need to add expr support in the next part
        streamer->advancePosition();
        next = streamer->peekNextTok();
        if (Lexer::tokTypeToString(next.type) == currentTok.content) {
            currParent = createNode(currParent, )    
        }
        
    }
}

Node* Parser::createNode(Node* parent, NodeType nodeType, std::vector<Tok> tokens){
    Node* node = new Node(parent, nodeType, tokens);
    parent->addChild(node);
   
}
