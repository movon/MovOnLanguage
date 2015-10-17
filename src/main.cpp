#include "Lexer.h"
#include <iostream>

int main(int argc, char** argv) {
	std::cout << "------------------ Program Started ------------------" << std::endl;
    Lexer::runLexer(argv);

	int a;
	std::cin >> a;
    return 0;
}