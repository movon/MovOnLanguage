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
src/Grammar/Program/E/E.h
src/Grammar/Program/E/E.cpp
src/Grammar/Program/E/E1.cpp
src/Grammar/Program/E/E1.h
src/Grammar/Program/E/E2.cpp
src/Grammar/Program/E/E2.h
src/Grammar/Program/E/E3.cpp
src/Grammar/Program/E/E3.h
src/Grammar/Program/E/E4.cpp
src/Grammar/Program/E/E4.h
src/Grammar/Program/E/E5.cpp
src/Grammar/Program/E/E5.h
src/Grammar/Program/E/F/F.cpp
src/Grammar/Program/E/F/F.h
src/Grammar/Program/E/F/F1.cpp
src/Grammar/Program/E/F/F1.h
src/Grammar/Program/E/P/P.cpp
src/Grammar/Program/E/P/P.h
src/Grammar/Program/E/P/P1.cpp
src/Grammar/Program/E/P/P1.h
src/Grammar/Program/E/P/P2.cpp
src/Grammar/Program/E/P/P2.h
src/Grammar/Program/E/P/P3.cpp
src/Grammar/Program/E/T/T.cpp
src/Grammar/Program/E/T/T.h
src/Grammar/Program/E/T/T1.cpp
src/Grammar/Program/E/T/T1.h
src/Grammar/Program/E/L/LOne.h
src/Grammar/Program/E/L/LOne.cpp
src/Grammar/Program/E/L/LOne1.cpp
src/Grammar/Program/E/L/LOne1.h
src/Grammar/Program/E/L/LOne2.cpp
src/Grammar/Program/E/L/LOne2.h
src/Grammar/Program/E/L/LTwo.cpp
src/Grammar/Program/E/L/LTwo.h
src/Grammar/Program/E/L/LTwo1.cpp
src/Grammar/Program/E/L/LTwo1.h
src/Grammar/Program/E/L/LTwo2.cpp
src/Grammar/Program/E/L/LTwo2.h
src/Grammar/Program/E/V/V.cpp
src/Grammar/Program/E/V/V.h
src/Grammar/Program/E/V/V1.cpp
src/Grammar/Program/E/V/V1.h
src/Grammar/Program/E/V/V2.cpp
src/Grammar/Program/E/V/V2.h
src/Grammar/Program/E/V/V3.cpp
src/Grammar/Program/E/V/V3.h
src/Grammar/Program/Program.h
src/Grammar/Program/Program.cpp
)
