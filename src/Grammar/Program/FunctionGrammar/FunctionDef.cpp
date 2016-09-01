#include "FunctionDef.h"

Node* FunctionDef::tryParse(TokStreamer* st){
	Tok temp = st->peekNextTok();
	if(BaseGrammar::expect(temp, tokType::FUNCTIONDEF)){
		Node::createNode(nullptr, NodeType::FUNCTIONDEF, st->getNextToken());
		return nullptr;
	}
	return nullptr;
}