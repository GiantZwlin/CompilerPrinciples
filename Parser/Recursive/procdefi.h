//
// Created by memoria on 19-5-14.
//

#ifndef COMPILERPRINCIPLES_PROCDEFI_H
#define COMPILERPRINCIPLES_PROCDEFI_H

#include "../../Lexer/token.h"
#include "procedh.h"
#include "block.h"
#include "procsuff.h"

void procdefi(Token &token) {
    if (token.code == InnerCode::getInnerCode("BEGIN"))
        return;
    else {
        procdh(token);
        block(token);
        if (token.code == InnerCode::getInnerCode(";")) {
            token = get_next_token();
        } else
            throw Syntax_Exception();
        procsuff(token);
    }
}

#endif //COMPILERPRINCIPLES_PROCDEFI_H
