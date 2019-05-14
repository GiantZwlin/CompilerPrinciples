//
// Created by memoria on 19-5-14.
//

#include<iostream>
#include "../../Lexer/lexer.h"
#include <vector>

using namespace std;

int main(int argc, char *argv[]) {
    Lexer lexer(argv[1]);
    //Don't forget to change the path
    vector<Token> v = lexer.lex();
    for (auto &i : v) {
        cout << "< " << i.word << " , " << i.code << " >" << endl;
    }
    return 0;
}