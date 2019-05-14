//
// Created by memoria on 19-5-14.
//

#ifndef COMPILERPRINCIPLES_PROGRAM_H
#define COMPILERPRINCIPLES_PROGRAM_H

#include "../../Lexer/token.h"
#include "headers.h"

void program(Token &token) {
    prohead(token);
    block(token);
}

#endif //COMPILERPRINCIPLES_PROGRAM_H
