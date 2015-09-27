#include "TokStreamer.h"

Streamer::Streamer(std::vector<Tok> t, int pos) {
        toks = t;
        i = pos;
        len = (signed) t.size();
}
 
void Streamer::advancePosition() {
        i++;
}
 
Tok Streamer::getNextToken(){
    if (i < len - 1) {
        return toks[++i];
    }
    else {
    	return Tok("", tokType::ENDOFINPUT);
    }
}
 
Tok Streamer::peekNextTok(){
    if (i < len - 1) {
		return toks[i + 1];
    }
    else {
    	return Tok("", tokType::ENDOFINPUT);
    }
}
