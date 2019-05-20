//
// Created by memoria on 19-5-14.
//

#ifndef COMPILERPRINCIPLES_BLOCK_H
#define COMPILERPRINCIPLES_BLOCK_H

#include "../../Lexer/token.h"
#include "consexpl.h"
#include "varexpl.h"

void block(Token &token) {
    consexpl(token);
    varexpl(token);
    procdefi(token);
    compsent(token);
}

#endif //COMPILERPRINCIPLES_BLOCK_H
