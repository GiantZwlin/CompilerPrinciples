//
// Created by memoria on 19-5-14.
//

#ifndef COMPILERPRINCIPLES_FACTOR_H
#define COMPILERPRINCIPLES_FACTOR_H

#include "../../Lexer/token.h"
#include "../../Lexer/innercode.h"
#include "utils.h"
#include "express.h"
#include "syntac_error.h"

void factor(Token &token) {
    if (token.code == InnerCode::getInnerCode("IDENTIFIER") || token.code == InnerCode::getInnerCode("UNSIGNED")) {
        token = get_next_token();
    } else if (token.code == InnerCode::getInnerCode("(")) {
        express(token);
        if (token.code == InnerCode::getInnerCode(")")) {
            token = get_next_token();
        } else {
            throw Syntax_Exception();
        }
    } else Syntax_Exception();
}

#endif //COMPILERPRINCIPLES_FACTOR_H
