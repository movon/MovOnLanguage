#ifndef STREAMER_H
#define STREAMER_H

#include <string>

class Streamer {
private:
	int i;
	string data;
public:
	Streamer(string data, int i);
	char peekNextChar();
	char getNextChar();
	void advancePosition();
};

#endif