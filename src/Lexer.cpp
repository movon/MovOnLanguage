#include "Lexer.h"

#include <iostream>
#include <fstream>
#include <algorithm>
#include <functional>

static std::set<std::string> keywords;
static std::set<std::string> flowOperators;
static std::set<std::string> operators;
static std::vector<Tok> tokens;

void Lexer::initSets() {
    keywords.insert("print");
    keywords.insert("int");
    keywords.insert("float");
    keywords.insert("function");

    operators.insert("=");
    operators.insert("<");
    operators.insert("<=");
    operators.insert(">");
    operators.insert(">=");
    operators.insert("!=");
    operators.insert("==");
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
 
bool Lexer::isKeyword(std::string content) {
        return keywords.find(content) != keywords.end();
}
 
 
bool Lexer::isOperator(std::string s) {
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
        case tokType::FUNCTIONNAME:
                return "FUNCTIONNAME";
        case tokType::FUNCTIONDEF:
            return "FUNCTIONDEF";
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
        case tokType::COMMA:
            return "COMMA";
        case tokType::ASSIGNMENT:
            return "ASSIGNMENT";
        }
}
 
void Lexer::addToParserTokens(Tok tok) {
        if (!trim(tok.content).empty()) {
                tokens.push_back(tok);
        }
}
 
void Lexer::printTokens() {
        for (size_t i = 0; i < tokens.size(); ++i)
        {
                std::cout << "\"" << tokens[i].content << "\"" << ": " << tokTypeToString(tokens[i].type) << std::endl;
        }
        //std::cout << std::endl;
        for (size_t i = 0; i < tokens.size(); ++i)
        {
                if (i != 0)
                        std::cout << ",";
                std::cout << '"' << tokens[i].content << '"';
        }
        std::cout << std::endl;
}
 
bool Lexer::isInt(const std::string& s) {
    auto it = s.begin();
    while (it != s.end() && std::isdigit(*it)) ++it;
    return !s.empty() && it == s.end();
}
 
bool Lexer::isFloat(const std::string& s) {
    std::istringstream iss(s);
    float f;
    iss >> std::noskipws >> f; // noskipws considers leading whitespace invalid
    // Check the entire std::string was consumed and if either failbit or badbit is set
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

bool Lexer::isFlowOperator(std::string& content) {
    return flowOperators.find(content) != flowOperators.end();
}

std::vector<Tok> Lexer::getTokens(){ return tokens; }

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
                if (chr == ' ' || chr == ';' || chr == '"' || chr == '(' || chr == ')' || chr == '{' || chr == '}' || chr == ',' || chr == '\n' || chr == '\t' || isOperator(std::string(1, chr))) {
                        if (isInString)
                        {
                                if (chr == '"') {
                                        //if std::string quotes ended - send it to parser
                                        tok.type = tokType::STRING;
                                        addToParserTokens(tok);
                                        isInString = false;
                                        tok.content = "";
                                }
                                else {
                                        //else, add the character to the std::string
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
                                        if (tok.content == "function") {
                                            tok.type = tokType::FUNCTIONDEF;
                                            addToParserTokens(tok);
                                            tok.content = "";
                                        }
                                        else {
                                            tok.type = tokType::KEYWORD;
                                            addToParserTokens(tok);
                                            tok.content = "";
                                        }
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
                                        tok.type = tokType::FUNCTIONNAME;
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
                                if (isOperator(std::string(1, chr))) {
                                        char nextChr = streamer->peekNextChar();
                                        if (isOperator(std::string(1, nextChr))) {
                                                streamer->advancePosition();
                                                addToParserTokens(Tok(std::string(1, chr) + std::string(1, nextChr), tokType::OPERATOR));
                                        }
                                        else {
                                            if (chr == '=') {
                                                addToParserTokens(Tok(std::string(1, chr), tokType::ASSIGNMENT));
                                            }
                                            else {
                                                addToParserTokens(Tok(std::string(1, chr), tokType::OPERATOR));
                                            }
                                        }
                                }
                                else if (chr == ';') {
                                        addToParserTokens(Tok(std::string(1, chr), tokType::DELIMITER));
                                }
                                else if (chr == ')') {
                                    addToParserTokens(Tok(std::string(1, chr), tokType::CLOSINGPARAN));
                                }
                                else if (chr == '{') {
                                    addToParserTokens(Tok(std::string(1, chr), tokType::OPENCURLY));
                                }
                                else if (chr =='}') {
                                    addToParserTokens(Tok(std::string(1, chr), tokType::CLOSINGCURLY));   
                                }
                                else if (chr == ',') {
                                    addToParserTokens(Tok(std::string(1, chr), tokType::COMMA));
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