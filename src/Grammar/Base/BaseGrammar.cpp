#include "BaseGrammar.h"


bool BaseGrammar::accept(Tok& tok, tokType t) {
    return tok.type == t;
}


bool BaseGrammar::expect(Tok& tok, tokType t) {
    if (accept(tok, t)) {
        return true;
    }
    error("Unexpected symbol");
    return false;
}


void BaseGrammar::error(std::string errormsg) {
    //needs implementing
    //in the error class most likely
	std::cout << errormsg << std::endl;
}

bool BaseGrammar::termByType(tokType t, TokStreamer* st) {
	return st->peekNextTok().type == t;
}

bool BaseGrammar::termByValue(std::string s, TokStreamer* st) {
	return st->peekNextTok().content == s;
}