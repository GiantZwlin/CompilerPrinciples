//
// Created by memoria on 19-5-14.
//

#ifndef COMPILERPRINCIPLES_IDSUFF_H
#define COMPILERPRINCIPLES_IDSUFF_H

#include "../../Lexer/token.h"
#include "../../Lexer/innercode.h"
#include "utils.h"
#include "syntac_error.h"

void idsuff(Token &token) {
    if (token.code == InnerCode::getInnerCode(",")) {
        token = get_next_token();
        if (token.code == InnerCode::getInnerCode("IDENTIFIER")) {
            token = get_next_token();
        } else {
            throw Syntax_Exception();
        }
        idsuff(token);
    }
}

#endif //COMPILERPRINCIPLES_IDSUFF_H
