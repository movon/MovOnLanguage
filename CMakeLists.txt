cmake_minimum_required(VERSION 3.2)
project(MovOnLanguage)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES src/main.cpp)

add_executable(MovOnLanguage ${SOURCE_FILES}
src/Lexing/Lexer.h
src/Lexing/Streamer.cpp
src/Base/Tok.h
src/Base/Errors.cpp
src/main.cpp
src/Lexing/Streamer.h
src/Parsing/TokStreamer.cpp
src/Base/Errors.h
src/Base/Node.cpp
src/Base/Tok.cpp
src/Parsing/TokStreamer.h
src/Lexing/Lexer.cpp
src/Base/Node.h
src/Parsing/Parser.h
src/Parsing/Parser.cpp
src/Grammar/Base/BaseGrammar.h
src/Grammar/Base/BaseGrammar.cpp
src/Grammar/Program/Expression/E1.cpp
src/Grammar/Program/Expression/E1.h
src/Grammar/Program/Expression/E2.cpp
src/Grammar/Program/Expression/E2.h
src/Grammar/Program/Expression/E3.cpp
src/Grammar/Program/Expression/E3.h
src/Grammar/Program/Expression/E4.cpp
src/Grammar/Program/Expression/E4.h
src/Grammar/Program/Expression/E5.cpp
src/Grammar/Program/Expression/E5.h)
