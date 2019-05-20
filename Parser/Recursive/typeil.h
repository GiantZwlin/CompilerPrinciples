//
// Created by memoria on 19-5-14.
//

#ifndef COMPILERPRINCIPLES_TYPEIL_H
#define COMPILERPRINCIPLES_TYPEIL_H

#include "../../Lexer/token.h"
#include "../../Lexer/innercode.h"
#include "utils.h"
#include "syntac_error.h"

void typeil(Token &token) {
    if (token.code == InnerCode::getInnerCode("INTEGER") || token.code == InnerCode::getInnerCode("LONG"))
        token = get_next_token();
    else
        throw Syntax_Exception();
}

#endif //COMPILERPRINCIPLES_TYPEIL_H
