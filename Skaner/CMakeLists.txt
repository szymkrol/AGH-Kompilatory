cmake_minimum_required(VERSION 4.1)
project(AGH_Kompilatory)

set(CMAKE_CXX_STANDARD 23)

include_directories(.)
include_directories(Scanner)

add_executable(AGH_Kompilatory
        Scanner/Scanner.cpp
        Scanner/Scanner.h
        FrozenPosition.h
        main.cpp
        Token.h
        Token.cpp
        HtmlHighlighter.cpp)
