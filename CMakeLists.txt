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
src/Grammar/Program/Expression/E.h
src/Grammar/Program/Expression/E.cpp
src/Grammar/Program/Expression/E1.cpp
src/Grammar/Program/Expression/E1.h
src/Grammar/Program/Expression/E2.cpp
src/Grammar/Program/Expression/E2.h
src/Grammar/Program/Expression/E3.cpp
src/Grammar/Program/Expression/E3.h
src/Grammar/Program/Expression/E4.cpp
src/Grammar/Program/Expression/E4.h
src/Grammar/Program/Expression/E5.cpp
src/Grammar/Program/Expression/E5.h
src/Grammar/Program/Expression/F/F.cpp
src/Grammar/Program/Expression/F/F.h
src/Grammar/Program/Expression/F/F1.cpp
src/Grammar/Program/Expression/F/F1.h
src/Grammar/Program/Expression/P/P.cpp
src/Grammar/Program/Expression/P/P.h
src/Grammar/Program/Expression/P/P1.cpp
src/Grammar/Program/Expression/P/P1.h
src/Grammar/Program/Expression/P/P2.cpp
src/Grammar/Program/Expression/P/P2.h
src/Grammar/Program/Expression/P/P3.cpp
src/Grammar/Program/Expression/T/T.cpp
src/Grammar/Program/Expression/T/T.h
src/Grammar/Program/Expression/T/T1.cpp
src/Grammar/Program/Expression/T/T1.h
src/Grammar/Program/Expression/L/LOne.h
src/Grammar/Program/Expression/L/LOne.cpp
src/Grammar/Program/Expression/L/LOne1.cpp
src/Grammar/Program/Expression/L/LOne1.h
src/Grammar/Program/Expression/L/LOne2.cpp
src/Grammar/Program/Expression/L/LOne2.h
src/Grammar/Program/Expression/L/LTwo.cpp
src/Grammar/Program/Expression/L/LTwo.h
src/Grammar/Program/Expression/L/LTwo1.cpp
src/Grammar/Program/Expression/L/LTwo1.h
src/Grammar/Program/Expression/L/LTwo2.cpp
src/Grammar/Program/Expression/L/LTwo2.h
src/Grammar/Program/Expression/V/V.cpp
src/Grammar/Program/Expression/V/V.h
src/Grammar/Program/Expression/V/V1.cpp
src/Grammar/Program/Expression/V/V1.h
src/Grammar/Program/Expression/V/V2.cpp
src/Grammar/Program/Expression/V/V2.h
src/Grammar/Program/Expression/V/V3.cpp
src/Grammar/Program/Expression/V/V3.h
)
