#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include <algorithm>
#include <functional>
#include <cctype>
#include <locale>
#include <vector>
#include <sstream>
#include "Tok.h"
#include "lexer.h"
#include "streamer.cpp"

using namespace std;

std::set<std::string> keywords;
std::set<std::string> operators;
std::vector<Tok> tokens;
int i = 0;


void initSets() {
    keywords.insert("print");
    keywords.insert("int");

    operators.insert("=");
    operators.insert("<");
    operators.insert("<=");
    operators.insert(">");
    operators.insert(">=");
    operators.insert("!=");
    operators.insert("==");
    operators.insert("===");
}

/*char streamer(string data) {
    if (i < data.length()) {
        return data.at(i++);
    }
    else {
        return 0;
    }
}*/

/*int findClosingQuotes(std::string data) { I don't think we need this, is that true?
    int openingQuotes = data.find("\"", i) + 1;
    int closingQuotes = data.find('"', openingQuotes);
    return closingQuotes - openingQuotes;
}*/

bool isKeyword(string content) {
    return keywords.find(content) != keywords.end();
}

bool isOrContainsAnOperator(string content) { //I needed to add this logic of going over each one because we can't be sure that it wasn't " int i=5 ;" no space in the i=5
    for (char& c : content) {
        std::string s(1, c);
        if (operators.find(s) != operators.end()) {
            return true;
        }
    }
    return false;
}

bool isOperator(string s) {
    return (operators.find(s) != operators.end());
}

struct Operation
{
    std::set<string> before;
    std::string op;
    std::set<string> after;
};

Operation seperateOperatorsFromBothSides(std::string content) {
    std::string s;
    std::string op = "";
    std::set<string> before;
    std::set<string> after;
    bool found_first_operator = false;
    for (char& c : content) {
        std::string a(1, c);
        s += a;
        if (operators.find(s) != operators.end()) {
            op += s;
            s = "";
        }
        else {
            if (op != "") {
                if (!found_first_operator) {
                    found_first_operator = true;
                }
                else {
    
                    throw ("Two or more operators were found in this simple instruction");
                } 
            }
            if (!found_first_operator){
                before.insert(s);    
            }
            else {
                after.insert(s);
            }            
            s = "";
        }
    }
    Operation result = {before, op, after};
    return result;
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

static string tokTypeToString(int tokType) {
    switch(tokType) {
        case 0:
            return "NONE";
        case 1:
            return "IDENTIFIER";
        case 2:
            return "KEYWORD";
        case 3:
            return "FUNCTION";
        case 4:
            return "PARAM";
        case 5:
            return "STRING";
        case 6:
            return "DELIMITER";
        case 7:
            return "OPERATOR";
        case 8:
            return "INT";
    }
}

void addToParserTokens(Tok tok) {
    if (!trim(tok.content).empty()) {
        tokens.push_back(tok);
}

void printTokens() {
    for(size_t i = 0; i < tokens.size(); ++i)
    {
      cout << "\"" << tokens[i].content << "\"" << ": " << tokTypeToString(tokens[i].type) << std::endl;
    }
    //cout << endl;
    for(size_t i = 0; i < tokens.size(); ++i)
    {
      if(i != 0)
        cout << ",";
      cout << '"' << tokens[i].content << '"';
    }
    cout << endl;
}

bool is_number(const std::string& s)
{
    std::string::const_iterator it = s.begin();
    while (it != s.end() && std::isdigit(*it)) ++it;
    return !s.empty() && it == s.end();
}

struct Primitive
{
  bool isPrimitive;
  tokType type;
};

Primitive checkIfPrimitive(std::string s) {
    Primitive result;
    if (is_number(s)) {
        Primitive result = {true, INT};
    }//TODO: Add else if's for every other primitive type
    else {
        Primitive not_primitive = {false, NONE};
        return not_primitive;
    }
    
    return result;
}

void process(std::set<std::string> v) {
    std::set<std::string>::iterator it;
    for (it = v.begin(); it != v.end(); ++it)
    {
        std::string s = *it;
        //std::cout << s << std::endl;
        if (isKeyword(s)) {
            addToParserTokens(Tok(s, KEYWORD));
            return;
        }
        Primitive primitive = checkIfPrimitive(s);
        if (primitive.isPrimitive) {
            addToParserTokens(Tok(s, primitive.type));
            return;
        }
        /*else if (isDelimiter(s)) {

        }*/
        //TODO: Add else if's for every type of token there is like EXPR
    }
}

string getNextToken() {

}

void runLexer() {
    initSets();
    string line;
    string data;
    std::ifstream myfile("src/code.mo");
    if (myfile.is_open()) {
        while (getline(myfile, line)) {
            data += line;
        }
    } else {
        cout << "The file is not at this location or does not exist" << endl;
        exit(1);
    }
    Streamer* streamer = new Streamer(data, 0);
    Tok tok = Tok("", NONE);
    bool isInString = false;
    char chr = streamer->getNextChar();
    while (chr != 0) {
        if (chr == ' ' || chr == ';' || chr == '"' || chr == '(' || chr == ')' || chr == ',' || chr =='\n' || isOperator(string(1, chr))) {
            if (isInString)
            {
                if (chr == '"') {
                    //if string quotes ended - send it to parser
                    tok.type = STRING;
                    addToParserTokens(tok);
                    isInString = false;
                    tok.content = "";
                } else {
                    //else, add the character to the string
                    tok.content += chr;
                }
            }
            else
            {
                if (chr == '"') {
                    //started string quotes
                    isInString = true;
                }
                //If I found a keyword - send it to parser.
                else if (isKeyword(tok.content))
                {
                    tok.type = KEYWORD;
                    addToParserTokens(tok);
                    tok.content = "";
                }
                else if (checkIfPrimitive(tok.content).isPrimitive) {//We need to make this a function so that I won't have to calculate if it's a Primitive twice
                    Primitive primitive = checkIfPrimitive(tok.content);
                    addToParserTokens(Tok(tok.content, primitive.type));
                    tok.content = "";
                }
                //It is another delimiter, send token to parser
                //TODO: check what token
                else
                {
                    tok.type = IDENTIFIER;
                    addToParserTokens(tok);
                    tok.content = "";
                    
                }

                //CHECK WHAT DELIMITER:
                if (isOperator(string(1, chr))) {
                    char nextChr = streamer->peekNextChar();
                    if (isOperator(string(1, nextChr))) {
                        streamer->advancePosition();
                        addToParserTokens(Tok(string(1, chr)+string(1, nextChr), OPERATOR));
                    }
                }
                else if (chr == ';') {
                    addToParserTokens(Tok(string(1, chr), DELIMITER));
                }
            }
        }
        //It is a normal chr, add to tok
        else {
            tok.content += chr;
        }
        chr = streamer->getNextChar();
    }
    printTokens();
}




