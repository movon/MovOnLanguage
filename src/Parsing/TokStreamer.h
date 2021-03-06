#ifndef TOK_STREAMER_H
#define TOK_STREAMER_H

#include <vector>
 
#include "../Base/Tok.h"
 
class TokStreamer {
private:
        int i;
        int len;
        std::vector<Tok> toks;
       
public:
        TokStreamer(std::vector<Tok> toks);
        void advancePosition();

        Tok getNextToken();
        Tok peekNextTok();

        int getIndex();
        void setIndex(int j);
        Tok getLastToken(int j);
};
 
#endif
