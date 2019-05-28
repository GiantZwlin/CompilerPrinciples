//
// Created by Zwlin on 2019/4/2 0002.
//

#include<iostream>
#include "lexer.h"
#include <vector>
#include <regex>

using namespace std;

int main(int argc, char *args[]) {
    Lexer lexer(args[1]);
    vector<Token> v = lexer.lex();
    cout << "Lex " << args[1] << endl;
    ofstream outfile;
    outfile.open("lex.out", ios::out | ios::trunc );
    for (auto &i : v) {
        outfile << "< " << i.word << " , " << i.code << " >" << endl;
    }
    outfile.close();
    return 0;
}
