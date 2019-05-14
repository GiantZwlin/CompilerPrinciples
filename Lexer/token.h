//
// Created by memoria on 19-5-14.
//

#ifndef COMPILERPRINCIPLES_TOKEN_H
#define COMPILERPRINCIPLES_TOKEN_H

#include <string>

struct Token {
    std::string word;
    int code;

    Token(std::string _word, int _code) {
        word = std::move(_word);
        code = _code;
    }
};

#endif //COMPILERPRINCIPLES_TOKEN_H
