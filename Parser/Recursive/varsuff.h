//
// Created by memoria on 19-5-14.
//

#ifndef COMPILERPRINCIPLES_VARSUFF_H
#define COMPILERPRINCIPLES_VARSUFF_H

#include "../../Lexer/token.h"
#include "../../Lexer/innercode.h"

void varsuff(Token &token) {
    if (token.code == InnerCode::getInnerCode("BEGIN") || token.code == InnerCode::getInnerCode("PROCEDURE")) {
        return;
    } else {

    }
}

#endif //COMPILERPRINCIPLES_VARSUFF_H
