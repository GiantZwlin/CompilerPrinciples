cmake_minimum_required(VERSION 3.13)
project("CompilerPrinciples")

set(CMAKE_CXX_STANDARD 11)

add_executable(Complier Lexer/main.cpp Lexer/lexutils.h Lexer/innercode.h Lexer/lexer.h Parser/Recursive/mian.cpp)