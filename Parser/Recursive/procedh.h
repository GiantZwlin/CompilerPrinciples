//
// Created by memoria on 19-5-14.
//

#ifndef COMPILERPRINCIPLES_PROCEDH_H
#define COMPILERPRINCIPLES_PROCEDH_H

#include "../../Lexer/token.h"
#include "../../Lexer/innercode.h"
#include "utils.h"
#include "syntac_error.h"
#include "argument.h"

void procdh(Token &token) {
    if (token.code == InnerCode::getInnerCode("PROCEDURE"))
        token = get_next_token();
    else
        throw Syntax_Exception();
    if (token.code == InnerCode::getInnerCode("IDENTIFIER"))
        token = get_next_token();
    else
        throw Syntax_Exception();
    argument(token);
}

#endif //COMPILERPRINCIPLES_PROCEDH_H
