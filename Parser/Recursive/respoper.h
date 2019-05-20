//
// Created by memoria on 19-5-14.
//

#ifndef COMPILERPRINCIPLES_RESPOPER_H
#define COMPILERPRINCIPLES_RESPOPER_H

#include "../../Lexer/token.h"
#include "utils.h"
#include "../../Lexer/innercode.h"
#include "syntac_error.h"

void respoper(Token &token) {
    if (token.code == InnerCode::getInnerCode("=") || token.code == InnerCode::getInnerCode("<") ||
        token.code == InnerCode::getInnerCode(">") || token.code == InnerCode::getInnerCode("<>") ||
        token.code == InnerCode::getInnerCode("<=") || token.code == InnerCode::getInnerCode(">=")) {
        token = get_next_token();
    } else
        throw Syntax_Exception();
}

#endif //COMPILERPRINCIPLES_RESPOPER_H
