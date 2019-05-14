//
// Created by memoria on 19-5-14.
//

#ifndef COMPILERPRINCIPLES_VARDEFI_H
#define COMPILERPRINCIPLES_VARDEFI_H

#include "../../Lexer/token.h"
#include "../../Lexer/innercode.h"
#include "utils.h"
#include "syntac_error.h"
#include "idsuff.h"
#include "typeil.h"

void vardefi(Token &token) {
    if (token.code == InnerCode::getInnerCode("IDENTIFIER")) {
        token = get_next_token();
    } else {
        throw Syntax_Exception();
    }
    idsuff(token);
    if (token.code == InnerCode::getInnerCode(":")) {
        token = get_next_token();
    } else {
        throw Syntax_Exception();
    }
    typeil(token);
}

#endif //COMPILERPRINCIPLES_VARDEFI_H
