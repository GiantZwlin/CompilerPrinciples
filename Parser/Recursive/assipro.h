//
// Created by memoria on 19-5-14.
//

#ifndef COMPILERPRINCIPLES_ASSIPRO_H
#define COMPILERPRINCIPLES_ASSIPRO_H

#include "../../Lexer/token.h"
#include "../../Lexer/innercode.h"
#include "utils.h"
#include "syntac_error.h"
#include "suffix.h"

void assipro(Token &token) {
    if (token.code == InnerCode::getInnerCode("IDENTIFIER")) {
        token = get_next_token();
    } else
        throw Syntax_Exception();
    suffix(token);
}

#endif //COMPILERPRINCIPLES_ASSIPRO_H
