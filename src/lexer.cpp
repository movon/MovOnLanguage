#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include "lexer.h"

using namespace std;

std::set<std::string> s;
int i = 0;

void initKeywordSet() {
    s.insert("print");
}


char streamer(string data) {
    if (i < data.length()) {
        return data.at(i++);
    }
    else {
        return 0;
    }
}

int findClosingQuotes(string data) {
    int openingQuotes = data.find("\"", i) + 1;
    int closingQuotes = data.find('"', openingQuotes);
    return closingQuotes - openingQuotes;
}

void handleKeyWord(string tok, string data) {
    string param = data.substr(data.find("\"", i) + 1, findClosingQuotes(data));
    if (tok == "print") {
        cout << param << endl;
    }
}

bool isKeyword(string tok) {
    if (s.find(tok) != s.end()) {
        return true;
    } else {
        return false;
    }
}

void runLexer() {
    initKeywordSet();
    string line;
    string data;
    ifstream myfile("code.mo");
    if (myfile.is_open()) {
        while (getline(myfile, line)) {
            data += line;
        }
    }
    string tok = "";
    char chr = streamer(data);
    while (chr != 0) {
        if (chr == ' ' || chr == ';' || chr == '\r') {
            if (isKeyword(tok)) {
                handleKeyWord(tok, data);
            }
            tok = "";
        } else {
            tok += chr;
        }
        chr = streamer(data);
        cout << "chr: " << chr << " tok: " << tok << endl;
    }
}




