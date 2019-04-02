//
// Created by Zwlin on 2019/4/2 0002.
//

#include<iostream>
#include "lexer.h"
#include <vector>

using namespace std;

int main() {
    Lexer lexer("D:\\CLionProjects\\Lexer\\example");
    vector<Token> v = lexer.lex();
    for (auto &i : v) {
        cout << "< " << i.word << " , " << i.code << " >" << endl;
    }
    return 0;
}
