#include "Lexing/Lexer.h"
#include <iostream>

int main(int argc, char** argv) {
	std::cout << "------------------ Program Started ------------------" << std::endl;
    Lexer* lex = new Lexer();
    Parser* parser = new Parser();
    std::vector<Tok> tokens = lex->runLexer(argv[1]);
    parser->run(tokens);
    return 0;
}