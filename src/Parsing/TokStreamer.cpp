#include "TokStreamer.h"

TokStreamer::TokStreamer(std::vector<Tok> t) {
    toks = t;
    i = -1; // Initial index
    len = (signed) t.size();
}
 
void TokStreamer::advancePosition() {
    i++;
}
 
Tok TokStreamer::getNextToken(){
    if (i < len - 1) {
        return toks[++i];
    }
    else {
    	return Tok("", tokType::ENDOFINPUT);
    }
}
 
Tok TokStreamer::peekNextTok(){
    if (i < len - 1) {
		return toks[i + 1];
    }
    else {
    	return Tok("", tokType::ENDOFINPUT);
    }
}

int TokStreamer::getIndex() {
    return i;
}

void TokStreamer::setIndex(int j) {
    i = j;
}

Tok TokStreamer::getLastToken(int j){
	if (i - j + 1 >= 0 && i - j + 1 < len) {
		return toks[i - j + 1];
	}
	
	return Tok("", tokType::ENDOFINPUT);
}