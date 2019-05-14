//
// Created by memoria on 19-5-14.
//

#ifndef COMPILERPRINCIPLES_CONSSUFF_H
#define COMPILERPRINCIPLES_CONSSUFF_H

#include "../../Lexer/token.h"
#include "../../Lexer/innercode.h"
#include "syntac_error.h"
#include "consdefi.h"
#include "utils.h"

void conssuff(Token &token) {
    if (token.code == InnerCode::getInnerCode(",")) {
        token = get_next_token();
        consdefi(token);
        conssuff(token);
    }
}

#endif //COMPILERPRINCIPLES_CONSSUFF_H
