cmake_minimum_required(VERSION 3.2)
project(MovOnLanguage)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES src/main.cpp)
add_executable(MovOnLanguage ${SOURCE_FILES} src/Lexer.h src/ParentNode.cpp src/Streamer.cpp src/Tok.h src/Errors.cpp src/main.cpp src/ParentNode.h src/Streamer.h src/TokStreamer.cpp src/Errors.h src/Node.cpp src/Parser.cpp src/Tok.cpp src/TokStreamer.h src/Lexer.cpp src/Node.h src/Parser.h src/TokenStreamer.h)
