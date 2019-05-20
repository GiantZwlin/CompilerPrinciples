//
// Created by memoria on 19-5-14.
//

#ifndef COMPILERPRINCIPLES_ADDOPER_H
#define COMPILERPRINCIPLES_ADDOPER_H

#include "../../Lexer/token.h"
#include "../../Lexer/innercode.h"
#include "utils.h"
#include "syntac_error.h"

void addoper(Token &token) {
    if (token.code == InnerCode::getInnerCode("+") || token.code == InnerCode::getInnerCode("-")) {
        token = get_next_token();
    } else
        throw Syntax_Exception();
}

#endif //COMPILERPRINCIPLES_ADDOPER_H
