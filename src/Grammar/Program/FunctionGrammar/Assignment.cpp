#include "Assignment.h"

Node* Assignment::tryParse(TokStreamer* st){
	Tok nextTok = st->peekNextTok();
	if(BaseGrammar::expect(nextTok, tokType::KEYWORD)){
		
	}
}