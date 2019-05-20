//
// Created by memoria on 19-5-14.
//

#ifndef COMPILERPRINCIPLES_WRITE_H
#define COMPILERPRINCIPLES_WRITE_H

#include "../../Lexer/token.h"
#include "../../Lexer/innercode.h"
#include "utils.h"
#include "syntac_error.h"
#include "idsuff.h"

void write(Token &token) {
    if (token.code == InnerCode::getInnerCode("WRITE")) {
        token = get_next_token();
    } else
        throw Syntax_Exception();
    if (token.code == InnerCode::getInnerCode("(")) {
        token = get_next_token();
    } else
        throw Syntax_Exception();
    if (token.code == InnerCode::getInnerCode("IDENTIFIER")) {
        token = get_next_token();
    } else
        throw Syntax_Exception();
    idsuff(token);
    if (token.code == InnerCode::getInnerCode(")")) {
        token = get_next_token();
    } else
        throw Syntax_Exception();
}

#endif //COMPILERPRINCIPLES_WRITE_H
