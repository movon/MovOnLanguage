#include "FuncionDef.h"

Node* FunctionDef::tryParse(TokStreamer* st){
	if(BaseGrammar::expect(st->peekNextTok(), tokType::FUNCTIONDEF)){
		Node::createNode(nullptr, NodeType::FUNCTIONDEF, st->getNextTok());
		return nullptr;
	}
	return nullptr;
}