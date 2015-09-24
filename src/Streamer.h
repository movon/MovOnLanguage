#ifndef STREAMER_H
#define STREAMER_H
 
#include <string>
#include <vector>
 
#include "Tok.h"
 
class Streamer {
private:
        int i;
        std::string data;
        int len;
        std::vector<Tok> toks;
        int currentToken;
       
public:
        Streamer(string data, int i);
        char peekNextChar();
        char getNextChar();
        void advancePosition();
       
        void printTokens();
        Tok getNextToken();
        Tok peekNextTok();
};
 
#endif