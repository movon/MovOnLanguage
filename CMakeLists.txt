cmake_minimum_required(VERSION 3.2)
project(MovOnLanguage)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

ADD_DEFINITIONS( -std=c++11 )



file(GLOB_RECURSE SOURCE_FILES
    "src/*.h"
    "src/*.cpp"
)

add_executable(MovOnLanguage ${SOURCE_FILES})

file(GLOB_RECURSE TEST_FILES
    "test/*.cpp"
    "test/*.h"
)

# Create a libgtest target to be used as a dependency by test programs


file(GLOB MAIN "src/main.cpp")

list(REMOVE_ITEM SOURCE_FILES ${MAIN})

add_executable(MovOnLanguageTest ${TEST_FILES} ${SOURCE_FILES})
target_link_libraries(MovOnLanguageTest gtest pthread gtest)


set(CMAKE_BUILD_TYPE Debug)
SET(CMAKE_CXX_FLAGS "-O0")
SET(CMAKE_C_FLAGS "-O0")
