//
// Created by memoria on 19-5-14.
//

#ifndef COMPILERPRINCIPLES_EXPRSUFF_H
#define COMPILERPRINCIPLES_EXPRSUFF_H

#include "../../Lexer/token.h"
#include "../../Lexer/innercode.h"
#include "utils.h"
#include "express.h"

void exprsuff(Token &token) {
    if (token.code == InnerCode::getInnerCode(",")) {
        token = get_next_token();
        express(token);
        exprsuff(token);
    } else
        return;
}

#endif //COMPILERPRINCIPLES_EXPRSUFF_H
