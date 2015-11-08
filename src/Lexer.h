//
// Created by talbor49 on 8/11/15.
//
#ifndef LEXER_H
#define LEXER_H
 
#include <string>
#include <set>
#include <cctype>
#include <locale>
#include <vector>
#include <sstream>
#include "Tok.h"
#include "Streamer.h"
#include <sstream>
 
class Lexer {
        public:
                struct Operation
                {
                std::set<std::string> before;
                std::string op;
                std::set<std::string> after;
                };
                 
                 
                struct Primitive
                {
                bool isPrimitive;
                tokType type;
                };
       
                static void initSets();
 
                static bool isKeyword(std::string content);

                static bool isType(std::string content);
 
                static bool isOperator(std::string s);

                static bool isCompareOperator(std::string s);
 
                static std::string tokTypeToString(tokType& tokType);
 
                static void printTokens();
 
                static bool isInt(std::string& s);
 
                static Primitive checkIfPrimitive(std::string s);
 
                static bool isFloat(const std::string& s);
               
                static bool isFlowOperator(std::string& content);
 
                static void runLexer(char** filename);
       
                static std::vector<Tok> getTokens();

                static void addToParserTokens(Tok tok);
};
 
 
#endif