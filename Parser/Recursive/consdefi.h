//
// Created by memoria on 19-5-14.
//

#ifndef COMPILERPRINCIPLES_CONSDEFI_H
#define COMPILERPRINCIPLES_CONSDEFI_H

#include "../../Lexer/token.h"
#include "../../Lexer/innercode.h"
#include "syntac_error.h"
#include "utils.h"

void consdefi(Token &token) {
    if (token.code == InnerCode::getInnerCode("IDENTIFIER"))
        token = get_next_token();
    else
        throw Syntax_Exception();
    if (token.code == InnerCode::getInnerCode("="))
        token = get_next_token();
    else
        throw Syntax_Exception();
    if (token.code == InnerCode::getInnerCode("UNSIGNED"))
        token = get_next_token();
    else
        throw Syntax_Exception();
}

#endif //COMPILERPRINCIPLES_CONSDEFI_H
