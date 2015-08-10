//
// Created by talbor49 on 8/11/15.
//
#include <string>


#ifndef MOVONLANGUAGE_LEXER_H
#define MOVONLANGUAGE_LEXER_H

void runLexer();

void initKeywordSet();

char streamer(std::string data);

bool isKeyword(std::string tok);

#endif //MOVONLANGUAGE_LEXER_H

