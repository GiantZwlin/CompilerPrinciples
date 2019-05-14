//
// Created by memoria on 19-5-14.
//

#ifndef COMPILERPRINCIPLES_PROHEAD_H
#define COMPILERPRINCIPLES_PROHEAD_H

#include "../../Lexer/token.h"
#include "../../Lexer/innercode.h"
#include "headers.h"
#include "syntac_error.h"

void prohead(Token &token) {
    if (token.code == InnerCode::getInnerCode("PROGRAM"))
        token = get_next_token();
    else
        throw Syntax_Exception();
    if (token.code == InnerCode::getInnerCode("IDENTIFIER"))
        token = get_next_token();
    else
        throw Syntax_Exception();
    if (token.code == InnerCode::getInnerCode(";"))
        token = get_next_token();
    else
        throw Syntax_Exception();
}

#endif //COMPILERPRINCIPLES_PROHEAD_H
