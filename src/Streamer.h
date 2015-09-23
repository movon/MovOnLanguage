#include <string>

class Streamer {
private:
	int i;
	std::string data;
	int len;
public:
	Streamer(string data, int i);
	char peekNextChar();
	char getNextChar();
	void advancePosition();
};
