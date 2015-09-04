//
// Created by talbor49 on 8/11/15.
//
#include <string>
#include "Tok.h"
#include <set>

#ifndef MOVONLANGUAGE_LEXER_H
#define MOVONLANGUAGE_LEXER_H

class lexer {
	public:
		static void runLexer();

	static void initSets();

	static std::string getNextToken();

	static bool isKeyword(std::string tok);

	static bool isOrContainsAnOperator(std::string content);

	static bool isOperator(std::string s);

	struct Operation;

	static Operation seperateOperatorsFromBothSides(std::string content);

	static std::string tokTypeToString(int tokType);

	static void addToParserTokens(Tok tok);

	static void printTokens();

	static bool is_number(const std::string& s);

	struct Primitive;

	static Primitive checkIfPrimitive(std::string s);

	static void process(std::set<std::string> v);



};


#endif //MOVONLANGUAGE_LEXER_H

