#include "Streamer.h"
 
#include <string>
#include <iostream>
 
Streamer::Streamer(std::string d, int pos) {
        data = d;
        i = pos;
        len = (signed) d.length();
}
 
char Streamer::peekNextChar() {
        if (i < len - 1) {
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
