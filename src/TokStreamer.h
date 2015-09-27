#ifndef TOK_STREAMER_H
#define TOK_STREAMER_H

#include <vector>
 
#include "Tok.h"
 
class Streamer {
private:
        int i;
        int len;
        std::vector<Tok> toks;
       
public:
        Streamer(std::vector<Tok> toks, int i);
        void advancePosition();

        Tok getNextToken();
        Tok peekNextTok();
};
 
#endif