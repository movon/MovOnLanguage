#include <iostream>
#include <fstream>
#include <string>

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

int main()
{
	string line;
	string data;
	ifstream myfile ("file.txt");
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


	return 0;
}

