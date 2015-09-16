#include "Lexer.h"

#include <iostream>
#include <fstream>
#include <algorithm>
#include <functional>

void Lexer::initSets() {
    keywords.insert("print");
    keywords.insert("int");
    keywords.insert("float");
    operators.insert("=");
    operators.insert("<");
    operators.insert("<=");
    operators.insert(">");
    operators.insert(">=");
    operators.insert("!=");
    operators.insert("==");
    operators.insert("===");
    operators.insert("-");
    operators.insert("+");
    operators.insert("*");
    operators.insert("/");

    flowOperators.insert("if");
    flowOperators.insert("else");
    flowOperators.insert("elsif");
}

// trim from start
static std::string &ltrim(std::string &s) {
    s.erase(s.begin(), std::find_if(s.begin(), s.end(), std::not1(std::ptr_fun<int, int>(std::isspace))));
    return s;
}

// trim from end
static std::string &rtrim(std::string &s) {
    s.erase(std::find_if(s.rbegin(), s.rend(), std::not1(std::ptr_fun<int, int>(std::isspace))).base(), s.end());
    return s;
}

// trim from both ends
static std::string &trim(std::string &s) {
    return ltrim(rtrim(s));
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
 
bool Lexer::isKeyword(string content) {
        return keywords.find(content) != keywords.end();
}
 
/*bool Lexer::isOrContainsAnOperator(string content) { //I needed to add this logic of going over each one because we can't be sure that it wasn't " int i=5 ;" no space in the i=5
        for (char& c : content) {
                std::string s(1, c);
                if (operators.find(s) != operators.end()) {
                        return true;
                }
        }
        return false;
}*/
 
bool Lexer::isOperator(string s) {
        return (operators.find(s) != operators.end());
}
 
std::string Lexer::tokTypeToString(tokType& tt) {
        switch (tt) {
        case tokType::NONE:
                return "NONE";
        case tokType::IDENTIFIER:
                return "IDENTIFIER";
        case tokType::KEYWORD:
                return "KEYWORD";
        case tokType::FUNCTION:
                return "FUNCTION";
        case tokType::PARAM:
                return "PARAM";
        case tokType::STRING:
                return "STRING";
        case tokType::DELIMITER:
                return "DELIMITER";
        case tokType::OPERATOR:
                return "OPERATOR";
        case tokType::INT:
                return "INT";
        case tokType::FLOAT:
            return "FLOAT";
        case tokType::FLOWOPERATOR:
            return "FLOWOPERATOR";
        case tokType::OPENPARAN:
            return "OPENPARAN";
        case tokType::CLOSINGPARAN:
            return "CLOSINGPARAN";
        case tokType::OPENCURLY:
            return "OPENCURLY";
        case tokType::CLOSINGCURLY:
            return "CLOSINGCURLY";
        }
}
 
void Lexer::addToParserTokens(Tok& tok) {
        if (!trim(tok.content).empty()) {
                tokens.push_back(tok);
        }
}
 
void Lexer::printTokens() {
        for (size_t i = 0; i < tokens.size(); ++i)
        {
                cout << "\"" << tokens[i].content << "\"" << ": " << tokTypeToString(tokens[i].type) << std::endl;
        }
        //cout << endl;
        for (size_t i = 0; i < tokens.size(); ++i)
        {
                if (i != 0)
                        cout << ",";
                cout << '"' << tokens[i].content << '"';
        }
        cout << endl;
}
 
bool Lexer::isInt(const std::string& s) {
    auto it = s.begin();
    while (it != s.end() && std::isdigit(*it)) ++it;
    return !s.empty() && it == s.end();
}
 
bool Lexer::isFloat(const std::string& s) {
    std::istringstream iss(s);
    float f;
    iss >> noskipws >> f; // noskipws considers leading whitespace invalid
    // Check the entire string was consumed and if either failbit or badbit is set
    return iss.eof() && !iss.fail();
}
 
Lexer::Primitive Lexer::checkIfPrimitive(std::string s) {
        Lexer::Primitive result;
        if (isInt(s)) {
            result = {true, tokType::INT };
        }//TODO: Add else if's for every other primitive type
        else if (isFloat(s)){
            result = {true, tokType::FLOAT};
        }
        else {
                Lexer::Primitive not_primitive = {false, tokType::NONE};
                return not_primitive;
        }
 
        return result;
}
 
void Lexer::process(std::set<std::string> v) {
        std::set<std::string>::iterator it;
        for (it = v.begin(); it != v.end(); ++it)
        {
                std::string s = *it;
                //std::cout << s << std::endl;
                if (isKeyword(s)) {
                        addToParserTokens(Tok(s, tokType::KEYWORD));
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

bool Lexer::isFlowOperator(std::string& content) {
    return flowOperators.find(content) != flowOperators.end();
}
void Lexer::runLexer() {
        initSets();
        std::string line;
        std::string data;
        std::ifstream myfile("src/code.mo");
        if(myfile.fail()){
            std::cout << "The file is not at this location or does not exist" << std::endl;
                exit(1);
        }
        while (getline(myfile, line)) {
                        data += line;
        }
                
        Streamer* streamer = new Streamer(data, -1);
        Tok tok = Tok("", tokType::NONE);
        bool isInString = false;
        char chr = streamer->getNextChar();
        while (chr != 0) {
                if (chr == ' ' || chr == ';' || chr == '"' || chr == '(' || chr == ')' || chr == '{' || chr == '}' || chr == ',' || chr == '\n' || isOperator(string(1, chr))) {
                        if (isInString)
                        {
                                if (chr == '"') {
                                        //if string quotes ended - send it to parser
                                        tok.type = tokType::STRING;
                                        addToParserTokens(tok);
                                        isInString = false;
                                        tok.content = "";
                                }
                                else {
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
                                        tok.type = tokType::KEYWORD;
                                        addToParserTokens(tok);
                                        tok.content = "";
                                }
                                else if (checkIfPrimitive(tok.content).isPrimitive) {//We need to make this a function so that I won't have to calculate if it's a Primitive twice
                                        Primitive primitive = checkIfPrimitive(tok.content);
                                        addToParserTokens(Tok(tok.content, primitive.type));
                                        tok.content = "";
                                }
                                else if (chr == '(') {        
                                    if (isFlowOperator(tok.content)) {
                                        tok.type = tokType::FLOWOPERATOR;
                                    }
                                    else {
                                        tok.type = tokType::FUNCTION;
                                    }
                                        addToParserTokens(tok);
                                        tok.content = "";
                                        addToParserTokens(Tok("(", tokType::OPENPARAN));
                                }
                                else if (isFlowOperator(tok.content)) {
                                    tok.type = tokType::FLOWOPERATOR;
                                    addToParserTokens(tok);
                                    tok.content = "";
                                }
                                //It is another delimiter, send token to parser
                                //TODO: check what token
                                else
                                {
                                        tok.type = tokType::IDENTIFIER;
                                        addToParserTokens(tok);
                                        tok.content = "";
 
                                }
 
                                //CHECK WHAT DELIMITER:
                                if (isOperator(string(1, chr))) {
                                        char nextChr = streamer->peekNextChar();
                                        if (isOperator(string(1, nextChr))) {
                                                streamer->advancePosition();
                                                addToParserTokens(Tok(string(1, chr) + string(1, nextChr), tokType::OPERATOR));
                                        }
                                        else {
                                            addToParserTokens(Tok(string(1, chr), tokType::OPERATOR));    
                                        }
                                }
                                else if (chr == ';') {
                                        addToParserTokens(Tok(string(1, chr), tokType::DELIMITER));
                                }
                                else if (chr == ')') {
                                    addToParserTokens(Tok(string(1, chr), tokType::CLOSINGPARAN));
                                }
                                else if (chr == '{') {
                                    addToParserTokens(Tok(string(1, chr), tokType::OPENCURLY));
                                }
                                else if (chr =='}') {
                                    addToParserTokens(Tok(string(1, chr), tokType::CLOSINGCURLY));   
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