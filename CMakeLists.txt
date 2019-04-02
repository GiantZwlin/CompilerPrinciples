cmake_minimum_required(VERSION 3.13)
project(Lexer)

set(CMAKE_CXX_STANDARD 11)

add_executable(Lexer Lexer/main.cpp Lexer/lexutils.h Lexer/innercode.h Lexer/lexer.h)