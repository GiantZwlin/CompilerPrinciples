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
#include "token.h"

class Lexer {
private:
    std::string filePath;
    std::ifstream File;
    bool noting;
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
        noting = false;
    }

    void add_to_table(std::vector<Token> &v, Token token) {
        if (!noting && !codeTable.isNotes(token.code)) {
            v.push_back(token);
        }
    }

    void deal_notes(int code) {
        if (code == InnerCode::getInnerCode("//")) {
            char c = getChar();
            while (c != '\n') {
                c = getChar();
            }
        } else if (codeTable.isNotes(code)) {
            noting = !noting;
        }
    }

    std::vector<Token> lex() {
        File.open(filePath);
        std::vector<Token> result;
        char c = getChar();
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
                int code = InnerCode::getInnerCode(LexUtils::toUpper(tmp));
                Token token = Token(tmp, code);
                add_to_table(result, token);
            } else {
                if (isdigit(c)) {
                    std::string tmp;
                    while (isdigit(c)) {
                        tmp += c;
                        c = getChar();
                    }
                    int code = InnerCode::getInnerCode("UNSIGNED");
                    Token token = Token(tmp, code);
                    add_to_table(result, token);
                } else {
                    if (codeTable.isDoubleChar(c)) {
                        std::string tmp;
                        tmp += c;
                        c = getChar();
                        std::string t_tmp = tmp + c;
                        int code = InnerCode::getInnerCode(t_tmp);
                        deal_notes(code);
                        if (code != -1) {
                            tmp = t_tmp;
                            Token token = Token(tmp, code);
                            add_to_table(result, token);
                            c = getChar();
                        } else {
                            code = InnerCode::getInnerCode(tmp);
                            deal_notes(code);
                            Token token = Token(tmp, code);
                            add_to_table(result, token);
                        }
                    } else {
                        std::string tmp;
                        tmp += c;
                        int code = codeTable.getInnerCode(tmp);
                        deal_notes(code);
                        Token token = Token(tmp, code);
                        add_to_table(result, token);
                        c = getChar();
                    }
                }
            }
        }
        return result;
    }
};

#endif //LEXER_LEXER_H
