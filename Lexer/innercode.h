//
// Created by Zwlin on 2019/4/2 0002.
//
#ifndef LEXER_INNERCODE_H
#define LEXER_INNERCODE_H

#include <string>
#include <map>
#include "lexutils.h"

class InnerCode {
private:
    std::map<std::string, int> codeTable;

public:
    InnerCode() {
        codeTable["PROGRAM"] = 1;
        codeTable["CONST"] = 2;
        codeTable["VAR"] = 3;
        codeTable["INTEGER"] = 4;
        codeTable["LONG"] = 5;
        codeTable["PROCEDURE"] = 6;
        codeTable["IF"] = 7;
        codeTable["THEN"] = 8;
        codeTable["WHILE"] = 9;
        codeTable["DO"] = 10;
        codeTable["READ"] = 11;
        codeTable["WRITE"] = 12;
        codeTable["BEGIN"] = 13;
        codeTable["END"] = 14;
        codeTable["ODD"] = 15;
        codeTable["+"] = 16;
        codeTable["-"] = 17;
        codeTable["*"] = 18;
        codeTable["/"] = 19;
        codeTable["="] = 20;
        codeTable["<>"] = 21;
        codeTable["<"] = 22;
        codeTable["<="] = 23;
        codeTable[">"] = 24;
        codeTable[">="] = 25;
        codeTable[","] = 26;
        codeTable["."] = 27;
        codeTable[";"] = 28;
        codeTable[":"] = 29;
        codeTable[":="] = 30;
        codeTable["("] = 31;
        codeTable[")"] = 32;
        codeTable["UNSIGNED"] = 33;
        codeTable["IDENTIFIER"] = 34;
        codeTable["#"] = 35;

    }

    int getInnerCode(const std::string& word) {
        if (codeTable[word] == 0) {
            for (char i : word) {
                if (!isalpha(i)) {
                    return -1;
                }
            }
            return codeTable["IDENTIFIER"];
        } else {
            return codeTable[word];
        }
    }

    bool isDoubleChar(char c) {
        std::string cc;
        cc += c;
        int code = getInnerCode(cc);
        return code == getInnerCode("<") || code == getInnerCode(">") || code == getInnerCode(":");
    }
};

#endif //LEXER_INNERCODE_H
