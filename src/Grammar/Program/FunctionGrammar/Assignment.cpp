#include "Assignment.h"

Node* Assignment::tryParse(TokStreamer* st){
	Tok nextTok = st->peekNextToken();
	if(BaseGrammar::expect(nextTok, tokType::KEYWORD)){
		
	}
}