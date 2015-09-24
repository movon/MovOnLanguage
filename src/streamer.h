#include <string>

#ifndef MOVONLANGUAGE_LEXER_H

using namespace std;

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
