//
// Created by Zwlin on 2019/4/2 0002.
//
#ifndef LEXER_LEXER_H
#define LEXER_LEXER_H

#include "lexutils.h"
#include "innercode.h"
#include <string>
#include <iostream>
#include <fstream>
#include <vector>

struct Token {
    std::string word;
    int code;

    Token(std::string _word, int _code) {
        word = std::move(_word);
        code = _code;
    }
};

class Lexer {
private:
    std::string filePath;
    std::ifstream File;
    InnerCode codeTable;

    char getChar() {
        char c;

        if (File.peek() != EOF) {
            File >> std::noskipws >> c;
            return c;
        }
        return '\0';
    }

public:

    explicit Lexer(std::string _file) {
        filePath = std::move(_file);
        codeTable = InnerCode();
    }

    std::vector<Token> lex() {
        File.open(filePath);
        std::vector<Token> result;
        char c = getChar();
        int w = 10;
        while (c != '\0') {
            if (LexUtils::isSpare(c)) {
                c = getChar();
                continue;
            }
            if (isalpha(c)) {
                int cnt = 0;
                std::string tmp;
                while (cnt < 20 && (isdigit(c) || isalpha(c))) {
                    tmp += c;
                    c = getChar();
                    cnt++;
                }
                int code = codeTable.getInnerCode(LexUtils::toUpper(tmp));
                Token token = Token(tmp, code);
                result.push_back(token);
            } else {
                if (isdigit(c)) {
                    std::string tmp;
                    while (isdigit(c)) {
                        tmp += c;
                        c = getChar();
                    }
                    int code = codeTable.getInnerCode("UNSIGNED");
                    Token token = Token(tmp, code);
                    result.push_back(token);
                } else {
                    if (codeTable.isDoubleChar(c)) {
                        std::string tmp;
                        tmp += c;
                        c = getChar();
                        std::string t_tmp = tmp + c;
                        int code = codeTable.getInnerCode(t_tmp);
                        if (code != -1) {
                            tmp = t_tmp;
                            Token token = Token(tmp, code);
                            result.push_back(token);
                            c = getChar();
                        } else {
                            code = codeTable.getInnerCode(tmp);
                            Token token = Token(tmp, code);
                            result.push_back(token);
                        }
                    } else {
                        std::string tmp;
                        tmp += c;
                        int code = codeTable.getInnerCode(tmp);
                        Token token = Token(tmp, code);
                        result.push_back(token);
                        c = getChar();
                    }
                }
            }
        }
        return result;
    }
};

#endif //LEXER_LEXER_H
