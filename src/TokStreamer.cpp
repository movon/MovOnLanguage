#include "TokStreamer.h"

TokStreamer::TokStreamer(std::vector<Tok> t, int pos) {
        toks = t;
        i = pos;
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
