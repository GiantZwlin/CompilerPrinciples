//
// Created by memoria on 19-5-14.
//

#ifndef COMPILERPRINCIPLES_ARGUMENT_H
#define COMPILERPRINCIPLES_ARGUMENT_H

#include "../../Lexer/token.h"
#include "../../Lexer/innercode.h"
#include "utils.h"
#include "syntac_error.h"
#include "typeil.h"

void argument(Token &token) {
    if (token.code == InnerCode::getInnerCode("(")) {
        token = get_next_token();
        if (token.code == InnerCode::getInnerCode("IDENTIFIER")) {
            token = get_next_token();
        } else
            throw Syntax_Exception();
        if (token.code == InnerCode::getInnerCode(":")) {
            token = get_next_token();
        } else
            throw Syntax_Exception();
        typeil(token);
        if (token.code == InnerCode::getInnerCode(")")) {
            token = get_next_token();
        } else
            throw Syntax_Exception();
    } else
        return;

}

#endif //COMPILERPRINCIPLES_ARGUMENT_H
