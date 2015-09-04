//
// Created by talbor49 on 8/11/15.
//
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
#include "Streamer.h"

#ifndef MOVONLANGUAGE_LEXER_H
#define MOVONLANGUAGE_LEXER_H


class Lexer {
	public:
		struct Operation
		{
	        std::set<string> before;
	        std::string op;
	        std::set<string> after;
		};
		 
		 
		struct Primitive
		{
	        bool isPrimitive;
	        tokType type;
		};
		static void initSets();

		static std::string getNextToken();

		static bool isKeyword(std::string tok);

		static bool isOrContainsAnOperator(std::string content);

		static bool isOperator(std::string s);

		static std::string tokTypeToString(int tokType);

		static void addToParserTokens(Tok tok);

		static void printTokens();

		static bool is_number(const std::string& s);

		static Primitive checkIfPrimitive(std::string s);

		static void process(std::set<std::string> v);

		

		static void runLexer();
};


#endif //MOVONLANGUAGE_LEXER_H