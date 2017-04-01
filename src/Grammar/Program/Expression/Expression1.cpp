#include "Expression1.h"

Node* E1::addL1(Job TParser, Node* E, TokStreamer* st) {
    Job LOneParser(LOne::tryParse, st);
    LOneParser.executeTask();
    Node* LOne_Node = LOneParser.getResult();
    while (LOne_Node != nullptr) {

        //maybe Node::createNode
        if (E->numChildren() == 1) {
            E->addChild(LOne_Node);
            TParser.executeTask();
            if (TParser.succeeded()) {
                E->addChild(TParser.getResult());
            }
            // else {
            //  TODO: error management here
            // 	error("Expected another term after operator \"+\" or \"-\"");
            // }
        }
        else {
            //Unite the children into an Expression
            Node* newE = Node::createNode(nullptr, NodeType::E);
            newE->addChild(E);
            Node* temp = newE;
            newE = E;
            E = temp;
            E->addChild(LOne_Node);
            TParser.executeTask();
            if (TParser.succeeded()) {
                E->addChild(TParser.getResult());
            }
            // else {
            //  TODO: error management here
            // 	error("Expected another term after operator \"+\" or \"-\"");
            // }
        }

        TParser.reset();
        LOneParser.reset();
        LOne_Node = LOneParser.getResult();
    }

    return E;
}

Node* E1::tryParse(TokStreamer* st) {
    Node* E;
	Job TParser(T::tryParse, st);
	TParser.executeTask();
    if(TParser.succeeded()) {
        E = Node::createNode(nullptr, NodeType::E);
        E->addChild(TParser.getResult());
        E = addL1(TParser, E, st);
        return E;
    }
    return nullptr;
}