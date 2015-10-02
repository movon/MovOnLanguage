cmake_minimum_required(VERSION 3.2)
project(MovOnLanguage)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES src/main.cpp)
add_executable(MovOnLanguage ${SOURCE_FILES} src/Streamer.cpp src/Streamer.h src/Lexer.cpp src/Lexer.h src/Tok.cpp src/Tok.h)
