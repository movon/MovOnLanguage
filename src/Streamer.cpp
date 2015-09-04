#include "Streamer.h"
#include <string>

using namespace std;
enum charType {LOGICAL_OPERATOR = 0, MATH_OPERATOR = 1, CHR_DELIMITER = 2};
Streamer::Streamer(string d, int pos) {
	this->data = d;
	this->i = pos;
}

char Streamer::peekNextChar() {
	if (this->i < this->data.length()) {
		return this->data.at(this->i+1);
	}
	else
	{
		return 0;
	}
	
}

char Streamer::getNextChar() {
	if (this->i < this->data.length()) {
		return this->data.at(this->i++);	
	}
	else
	{
		return 0;
	}

}

void Streamer::advancePosition() {
	this->i++;
}