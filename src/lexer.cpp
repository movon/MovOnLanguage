#include <iostream>
#include <fstream>
#include <string>
#include "lexer.h"

using namespace std;

int i = 0;

char streamer(string data) {
	if (i < data.length()) {
		return data.at(i++);
	}
	else {
		return 0;
	}
}

void runLexer()
{
	string line;
	string data;
	ifstream myfile ("code.mo");
	if (myfile.is_open()) 
	{
		while(getline(myfile, line)) 
		{
			data += line;
		}
	}
	char chr = streamer(data);
	while (chr != 0) {
		cout << chr << endl;
		chr = streamer(data);
	}
}

