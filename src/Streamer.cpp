#include "Streamer.h"
#include <string>

using namespace std;
enum charType {LOGICAL_OPERATOR = 0, MATH_OPERATOR = 1, CHR_DELIMITER = 2};
Streamer::Streamer(string d, int pos) {
	data = d;
	i = pos;
}

char Streamer::peekNextChar() {
	if (i < data.length()) {
		return data.at(i+1);
	}
	else
	{
		return 0;
	}
	
}

char Streamer::getNextChar() {
	i = i + 1;
	if (i < data.length()) {
		return data.at(i);
	}
	else
	{
		return 0;
	}

}

void Streamer::advancePosition() {
	i++;
}