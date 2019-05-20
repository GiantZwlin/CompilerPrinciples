//
// Created by memoria on 19-5-14.
//

#ifndef COMPILERPRINCIPLES_COMPSENT_H
#define COMPILERPRINCIPLES_COMPSENT_H

#include "../../Lexer/token.h"
#include "../../Lexer/innercode.h"
#include "utils.h"
#include "syntac_error.h"
#include "sentense.h"
#include "sentsuff.h"

void compsent(Token &token) {
    if (token.code == InnerCode::getInnerCode("BEGIN")) {
        token = get_next_token();
    } else
        throw Syntax_Exception();
    sentence(token);
    sentsuff(token);
    if (token.code == InnerCode::getInnerCode("END")) {
        token = get_next_token();
    } else
        throw Syntax_Exception();
}

#endif //COMPILERPRINCIPLES_COMPSENT_H
