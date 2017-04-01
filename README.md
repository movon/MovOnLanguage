# MovOnLanguage
MovOnLanguage is an interpreted programming language, with easy to read syntax.
The interpreter is written in C++11.

# Installation
## Install googletest
```
cd googletest
mkdir build && cd build
cmake ../
make
sudo make install
```
## Compile MovOnLanguage
from the project root folder:
```
cmake .
make
./MovOnLanguage <main file>
```

## How it works
First, the lexer (comes from Lexical Analysis) converts the code from characters to tokens.
Second, the parser takes the tokens that the lexer generated, and applies the rules of the language's grammar.

Useful notes:
1).If your data becomes corrupted then add a case for it in tokTypeToString

2). -1 > 1 -> true! turn 1 to signed. happened in -1 >= .length()
