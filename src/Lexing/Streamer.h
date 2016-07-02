#ifndef STREAMER_H
#define STREAMER_H
 
#include <string>
#include <vector>
 
#include "../Base/Tok.h"
 
class Streamer {
private:
        int i;
        std::string data;
        int len;
        std::vector<Tok> toks;
public:
        Streamer(std::string data, int i);
        char peekNextChar();
        char getNextChar();
        void advancePosition();
};
 
#endif
