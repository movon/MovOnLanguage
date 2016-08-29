#include "FuncionDef.h"

Node* tryParse(TokStreamer* st){
	if(BaseGrammar::expect(st->peekNextTok(), tokType::FUNCTIONDEF){
		Node::createNode(nullptr, NodeType::FUNCTIONDEF, st->getNextTok())
		
	}
}