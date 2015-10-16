#include "Parser.h"

ParentNode* currParent = nullptr;
Node* prevNode = nullptr;
std::vector<Tok> currentStatement;
std::vector<Tok> prevStatement;
std::vector<Node*> nodes;

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
            currParent = createNode(currParent, NodeType::CREATION, currNodeToks);
            currNodeToks.clear();
            createNode(currParent, )    
        }
        else {
            //error() or something along those lines
        }
        
    }
}

Node* Parser::createNode(Node* parent, NodeType nodeType){
    Node* node = new Node(parent, nodeType);
    if(parent != nullptr){
       parent->addChild(node);
    }

    return node;   
}

Node* Parser::createNode(Node* parent, NodeType nodeType, Tok t) {
    Node* node = new Node(parent, nodeType, t);
    if (parent != nullptr) {
        parent->addChild(node);
    }

    return node;
}



//Grammar for Expressions:
// E --> T {LOne T} | "+" "+" ID | ID "+" "+" | "-" "-" ID | ID "-" "-"
// T --> F {LTwo F}
// F --> P ["^" F]
// P --> V | "(" E ")" | "-" T | "+" T //V is constants and identifiers
// LOne -> "+" | "-"
// LTwo -> "*" | "/"

//Grammer for BEXP:
// BEXP -> lvl1bexp {OR lvl1bexp}
// lvl1bexp -> lvl2bexp {(AND|XOR) lvl2bexp}
//lvl2bexp -> NOT lvl3bexp | lvl3bexp
//lvl3bexp -> TRUE | FALSE | E COMPARISON_OPERATOR E


bool Parser::termByType(tokType t, TokStreamer* st) {
    if (st->getNextToken().type == t) {
        //maybe createNode
        return true;
    }

    return false;
}

bool Parser::termByValue(std::string s, TokStreamer* st) {
    if (st->getNextToken().content == s) {
        //maybe createNode
        return true;
    }

    return false;
}

bool Parser::LOne(TokStreamer* st) {
    int save = st->getIndex();
    if (LOne1(st)) {
        //maybe createNode
        return true;
    }

    st->setIndex(save);
    if (Lone2(st)) {
        //maybe createNode
        return true;
    }

    //maybe st->setIndex(save);
    return false;
}

bool Parser::LOne1(TokStreamer* st) {
    if (termByValue("+", st)) {
        //maybe createNode
        return true;
    }

    return false;
}

bool Parser::LOne2(TokStreamer* st) {
    if (termByValue("-", st)) {
        //maybe createNode
        return true;
    }

    return false;
}

bool Parser::LTwo(TokStreamer* st) {
    int save = st->getIndex();
    if (LTwo1(st)) {
        //maybe createNode
        return true;
    }

    st->setIndex(save);
    if (LTwo2(st)) {
        //maybe createNode
        return true;
    }

    //maybe st->setIndex(save);
    return false;
}

bool Parser::LTwo1(TokStreamer* st) {
    if (termByValue("*", st)) {
        //maybe createNode
        return true;
    }

    return false;
}

bool Parser::LTwo2(TokStreamer* st) {
    if (termByValue("/", st)) {
        //maybe createNode
        return true;
    }

    return false; 
}

bool Parser::E(TokStreamer* st) {
    int save = st->getIndex();
    if (E1(st)) {
        return true;
    }
    
    st->setIndex(save);
    if (E2(st)) {
        return true;
    }

    st->setIndex(save);
    if (E3(st)) {
        return true;
    }

    st->setIndex(save);
    if (E4(st)) {
        return true;
    }

    st->setIndex(save);
    if (E5(st)) {
        return true;
    }

    //maybe st->setIndex(save);
    return false;
}

bool Parser::E1(TokStreamer* st) {
    Node* E;
    if (T(st)) {
        //maybe createNode
        Node* result;
        result = nodes.back();
        nodes.pop_back();
        E = createNode(nullptr, NodeType::E);
        E->addChild(result);
        while (LOne(st)) {
            //maybe createNode
            if (E->numChildren() == 1) {
                result = nodes.back();
                nodes.pop_back();
                E->addChild(result);
                if (T(st)) {
                    result = nodes.back();
                    nodes.pop_back();
                    E->addChild(result);
                }
                else {
                    error("Expected another term after operator \"+\" or \"-\"");
                }
            }
            else {  
                //Unite the children into an E
                Node* newE = createNode(nullptr, nodeType::E);
                E->changeParent(newE);
                Node* temp = newE;
                newE = E;
                E = temp;
                result = nodes.back();//LOne
                nodes.pop_back();
                E->addChild(result);
                if (T(st)) {
                    result = nodes.back();
                    nodes.pop_back();//T
                    E->addChild(result);
                }
                else {
                    error("Expected another term after operator \"+\" or \"-\"");
                }
            }
        }
        nodes.push_back(E);
        return true;
    }
    return false;
}

bool Parser::E2(TokStreamer* st) {
    if (termByValue("+", st) && termByValue("+", st)) {
        if (termByType(tokType::IDENTIFIER, st)) {//we need to see how we get this identifiers name
            Tok id = st->getLastToken(1);
            Node* C = createNode(nullptr, NodeType::CREMENTER);
            C->addChild(createNode(C, NodeType::ADD));
            C->addChild(createNode(C, NodeType::ID, id));
            nodes.push_back(C);
            return true;
        }
        else {
            error("Expected an identifier after \"++\" operation");
        }
    }

    return false;
}

bool Parser::E3(TokStreamer* st) {
    if (termByType(tokType::IDENTIFIER, st)) {//we need to see how we get this identifiers name
        if (termByValue("+", st) && termByValue("+")) {
            std::string name = 
            return true;
        }
    }

    return false;
}

bool Parser::E4(TokStreamer* st) {
    if (termByValue("-", st) && termByValue("-", st)) {
        if (termByType(tokType::IDENTIFIER, st)) {//we need to see how we get this identifiers name
            //maybe createNode
            return true;
        }
        else {
            error("Expected an identifier after \"--\" operation")
        }
    }

    return false;
}

bool Parser::E5(TokStreamer* st) {
    if (termByType(tokType::IDENTIFIER, st)) {//we need to see how we get this identifiers name
        if (termByValue("-", st) && termByValue("-", st)) {
            //maybe createNode
            return true;
        }
    }

    return false;
}

bool Parser::T(TokStreamer* st) {
    if (T1(st)) {
        return true;
    }
    return false;
}

bool Parser::T1(TokStreamer* st) {
    Node* T;
    if (F(st)) {
        Node* node;
        node = nodes.back();
        nodes.pop_back();
        T = createNode(nullptr, tokType::E);
        T->addChild(node);
        while (LTwo(st)) {
            if (F(st)) {
                
            }
            else {
                error("Expected another term after operator \"*\" or \"/\"");
            }
        }
        return true;
    }
    
    return false;
}

bool Parser::F(TokStreamer* st) {
    if (F1(st)) {
        return true;
    }
    
    //maybe st->setIndex(save);
    return false;
}

bool Parser::F1(TokStreamer* st) {

    if (P(st)) {
        
        if (termByValue("^", st)) {
            if (F(st)) {
                //maybe createNode
            }
            else {
                error("Expected another term after operator \"^\"");
            }
        }
        return true;
    }
    
    return false;
}

bool Parser::P(TokStreamer* st) {
    int save = st->getIndex();
    if (P1(st)) {
        //maybe createNode
        return true;
    }
    
    st->setIndex(save);
    if (P2(st)) {
        //maybe createNode
        return true;
    }

    st->setIndex(save);
    if (P3(st)) {
        //maybe createNode
        return true;
    }

    //maybe st->setIndex(save);
    return false;
}

bool Parser::P1(TokStreamer* st) {
    if (V(st)) {
        //maybe createNode
        return true;
    }
    
    return false;
}

bool Parser::P2(TokStreamer* st) {
    if (termByType(tokType::OPENPARAN, st)) {
        if (E(st)) {
            //maybe createNode //probably not in here though
            if (termByType(tokType::CLOSINGPARAN, st)) {
                return true;
            }
            else {
                error("Expected closing paran after expression");
            }
        }
        else {
            error("Expected expression after opening paran");
        }
    }
    
    return false;
}

bool Parser::P3(TokStreamer* st) {
    if (termByValue("-", st)) {
        if (T(st)) {
            //maybe createNode
            return true;
        }
        else {
            error("Expected a term after unirary minus sign");
        }
    }
    
    return false;
}

bool Parser::P4(TokStreamer* st) {
    if (termByValue("+", st)) {
        if (T(st)) {
            //maybe createNode
            return true;
        }
        else {
            error ("Expected a term after unirary plus sign");
        }
    }

    return false;
}

bool Parser::V(TokStreamer* st) {
    int save = st->getIndex();
    if (V1(st)) {
        //maybe createNode
        return true;
    }

    st->setIndex(save);
    if (V2(st)) {
        //maybe createNode
        return true;
    }

    st->setIndex(save);
    if (V3(st)) {
        //maybe createNode
        return true;
    }

    //...

    //maybe st->setIndex(save);
    return false;
}

bool Parser::V1(TokStreamer* st) {
    if (termByType(tokType::INT, st)) {
        //maybe createNode
        return true;
    }

    return false;
}

bool Parser::V2(TokStreamer* st) {
    if (termByType(tokType::FLOAT, st)) {
        //maybe createNode
        return true;
    }

    return false;
}

bool Parser::V3(TokStreamer* st) {
    if (termByType(tokType::IDENTIFIER, st)) {
        //maybe createNode
        return true;
    }

    return false;
}
