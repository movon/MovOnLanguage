#include "Streamer.h"
 
#include <string>
#include <iostream>
 
Streamer::Streamer(std::string d, int pos) {
        data = d;
        i = pos;
        len = (signed) d.length();
        currentToken = -1;
}
 
char Streamer::peekNextChar() {
        if (i < len) {
                return data.at(i+1);
        }
        else
        {
                return 0;
        }
}
 
char Streamer::getNextChar() {
        if (i < len - 1) {
                return data.at(++i);
        }
        else
        {
                return 0;
        }
}
 
void Streamer::advancePosition() {
        i++;
}
 
void Streamer::addToken(Tok tok){
        toks.push_back(tok);   
}
 
Tok Streamer::getNextToken(){
        return toks[++currentToken];
}
 
Tok Streamer::peekNextTok(){
        return toks[currentToken + 1];
}
void Streamer::printTokens() {
        for (int i = 0; i < tokens.size(); ++i)
        {
                std::cout << "\"" << tokens[i].content << "\"" << ": " << tokTypeToString(tokens[i].type) << std::endl;
        }
        //std::cout << std::endl;
        for (int i = 0; i < tokens.size(); ++i)
        {
                if (i != 0)
                        std::cout << ",";
                std::cout << '"' << tokens[i].content << '"';
        }
        std::cout << std::endl;
}