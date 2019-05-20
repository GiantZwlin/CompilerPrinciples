//
// Created by memoria on 19-5-14.
//

#ifndef COMPILERPRINCIPLES_MULOPER_H
#define COMPILERPRINCIPLES_MULOPER_H

#include "../../Lexer/token.h"
#include "syntac_error.h"
#include "utils.h"
#include "../../Lexer/innercode.h"

void muloper(Token &token){
    if (token.code == InnerCode::getInnerCode("*") || token.code == InnerCode::getInnerCode("/")) {
        token = get_next_token();
    } else
throw Syntax_Exception();
}
#endif //COMPILERPRINCIPLES_MULOPER_H
