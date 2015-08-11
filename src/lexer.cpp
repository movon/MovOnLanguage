#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include <algorithm>
#include <functional>
#include <cctype>
#include <locale>
#include "Tok.h"
#include "lexer.h"

using namespace std;

std::set<std::string> keywords;
int i = 0;


void initSets() {
    keywords.insert("print");
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

bool isKeyword(string tok) {
    return keywords.find(tok) != keywords.end();
}


// trim from start
static inline std::string &ltrim(std::string &s) {
    s.erase(s.begin(), std::find_if(s.begin(), s.end(), std::not1(std::ptr_fun<int, int>(std::isspace))));
    return s;
}

// trim from end
static inline std::string &rtrim(std::string &s) {
    s.erase(std::find_if(s.rbegin(), s.rend(), std::not1(std::ptr_fun<int, int>(std::isspace))).base(), s.end());
    return s;
}

// trim from both ends
static inline std::string &trim(std::string &s) {
    return ltrim(rtrim(s));
}

void sendToParser(Tok *tok) {
    if (!trim(tok->content).empty()) {
        cout << tok->content << endl;
    }
}


void runLexer() {
    initSets();
    string line;
    string data;
    ifstream myfile("code.mo");
    if (myfile.is_open()) {
        while (getline(myfile, line)) {
            data += line;
        }
    }
    Tok* tok = new Tok("", NONE);
    bool isInString = false;
    char chr = streamer(data);
    while (chr != 0) {
        if (chr == ' ' || chr == ';' || chr == '"' || chr == '(' || chr == ')') {
            if (isInString)
            {
                if (chr == '"') {
                    //if string quotes ended - send it to parser
                    tok->type = STRING;
                    sendToParser(tok);
                    isInString = false;
                    tok->content = "";
                } else {
                    //else, add the character to the string
                    tok->content += chr;
                }
            }
            else
            {
                if (chr == '"') {
                    //started string quotes
                    isInString = true;
                }
                //If I found a keyword - send it to parser.
                else if (isKeyword(tok->content))
                {
                    tok->type = KEYWORD;
                    sendToParser(tok);
                    tok->content = "";
                }
                //It is another delimiter, send token to parser
                //TODO: check what token
                else
                {
                    sendToParser(tok);
                    tok->content = chr;
                    sendToParser(tok);
                    tok->content = "";
                }
            }
        }
        //It is a normal chr, add to tok
        else {
            tok->content += chr;
        }
        chr = streamer(data);
    }
}




