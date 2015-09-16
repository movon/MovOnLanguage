#ifndef STREAMER_H
#define STREAMER_H

#include <string>

class Streamer {
private:
	int i;
	std::string data;
public:
	Streamer(std::string data, int i);
	char peekNextChar();
	char getNextChar();
	void advancePosition();
};

#endif