//
// Created by talbor49 on 8/11/15.
//
#ifndef MOVONLANGUAGE_LEXER_H
#define MOVONLANGUAGE_LEXER_H

#include "Parser.h" 
#include "Tok.h"
#include "Streamer.h"
#include <string>
#include <set>
#include <cctype>
#include <locale>
#include <vector>
#include <sstream>
#include <sstream>
#include <fstream>
#include <algorithm>

class Lexer {
        
  private:
    std::set<std::string> keywords;
    std::set<std::string> types;
    std::set<std::string> flowOperators;
    std::set<std::string> operators;
    std::set<std::string> compareOperators;
    std::vector<Tok> tokens;
    Streamer* streamer;
        
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
  
      Lexer();
      
      void initSets();
  
      bool isKeyword(std::string content);
  
      bool isType(std::string content);
  
      bool isOperator(std::string s);
  
      bool isCompareOperator(std::string s);
  
      std::string tokTypeToString(tokType& tokType);
  
      void printTokens();
  
      bool isInt(std::string& s);
  
      Primitive checkIfPrimitive(std::string s);
  
      bool isFloat(const std::string& s);
     
      bool isFlowOperator(std::string& content);
  
      void handleChar(char chr, bool& isInString, Tok& tok);
  
      std::vector<Tok> runLexer(char* filename);
  
      std::vector<Tok> getTokens();
  
      void addToParserTokens(Tok tok);
};
 
 
#endif //MOVONLANGUAGE_LEXER_H