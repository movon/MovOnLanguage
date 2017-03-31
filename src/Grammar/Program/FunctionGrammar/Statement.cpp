#include "Statement.h"

Node* Statement::tryParse(TokStreamer* st){
	int save = st->getIndex();
	Node* mainNode = nullptr;
	Node* nextNode = nullptr;
	//check for a functiondef
	mainNode = FunctionDef::tryParse(st);
	if(mainNode != nullptr){
		//goto the next statement
		nextNode = Statement::tryParse(st);
		mainNode->addChild(nextNode);
		return mainNode;
	}
	st->setIndex(save);
	//check for a function call
	mainNode = FuncCall::tryParse(st);
	if(mainNode != nullptr){
		///goto the next statement
		nextNode = Statement::tryParse(st);
		mainNode->addChild(nextNode);
		return mainNode;
	}
	st->setIndex(save);
	//check for a flow statement
	mainNode = Flow::tryParse(st);
	if(mainNode != nullptr){
		//goto the next statement
		nextNode = Statement::tryParse(st);
		mainNode->addChild(nextNode);
		return mainNode;
	}
	st->setIndex(save);
	//check for an assignment
	mainNode = Assignment::tryParse(st);
	if(mainNode != nullptr){
		//goto the next statement
		nextNode = Statement::tryParse(st);
		mainNode->addChild(nextNode);
		return mainNode;
	}
	st->setIndex(save);
	//check for a keyword
	mainNode = Keyword::tryParse(st);
	if(mainNode != nullptr){
		//goto the next statement
		nextNode = Statement::tryParse(st);
		mainNode->addChild(nextNode);
		return mainNode;
	}
	//it's not a statement return nullptr
	return mainNode;

}
