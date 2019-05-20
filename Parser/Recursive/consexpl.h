//
// Created by memoria on 19-5-14.
//

#ifndef COMPILERPRINCIPLES_CONSEXPL_H
#define COMPILERPRINCIPLES_CONSEXPL_H

#include "../../Lexer/token.h"
#include "../../Lexer/innercode.h"
#include "syntac_error.h"
#include "utils.h"
#include "consdefi.h"
#include "conssuff.h"

void consexpl(Token &token) {
    if (token.code == InnerCode::getInnerCode("CONST")) {
        token = get_next_token();
        consdefi(token);
        conssuff(token);
    }
}

#endif //COMPILERPRINCIPLES_CONSEXPL_H
