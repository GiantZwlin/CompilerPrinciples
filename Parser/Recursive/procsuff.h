//
// Created by memoria on 19-5-14.
//

#ifndef COMPILERPRINCIPLES_PROCSUFF_H
#define COMPILERPRINCIPLES_PROCSUFF_H

#include "../../Lexer/token.h"
#include "../../Lexer/innercode.h"
#include "procedh.h"
#include "block.h"

void procsuff(Token &token) {
    if (token.code == InnerCode::getInnerCode("BEGIN")) {
        return;
    } else {
        procdh(token);
        block(token);
        if (token.code == InnerCode::getInnerCode(";")) {
            token = get_next_token();
        } else
            throw Syntax_Exception();
        procsuff(token);
    }
}

#endif //COMPILERPRINCIPLES_PROCSUFF_H
