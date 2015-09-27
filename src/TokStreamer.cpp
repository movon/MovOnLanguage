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
        return toks[++i];
}
 
Tok Streamer::peekNextTok(){
        return toks[i + 1];
}
