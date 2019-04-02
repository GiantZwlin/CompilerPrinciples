//
// Created by Zwlin on 2019/4/2 0002.
//
#ifndef LEXER_UTILS_H
#define LEXER_UTILS_H

#include <string>

class LexUtils {
public:

    static bool isSpare(char c) {
        return c == '\n' || c == '\t' || c == '\r' || c == ' ';
    }

    static std::string toUpper(std::string str) {
        std::string tmp;
        for (int i = 0; i <= str.length(); i++) {
            if (islower(str[i])) {
                tmp += (str[i] - 'a') + 'A';
            }
        }
        return tmp;
    }
};

#endif //LEXER_UTILS_H
