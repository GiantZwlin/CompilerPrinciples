//
// Created by memoria on 19-5-14.
//

#ifndef COMPILERPRINCIPLES_WHILESENT_H
#define COMPILERPRINCIPLES_WHILESENT_H

#include "../../Lexer/token.h"
#include "../../Lexer/innercode.h"
#include "utils.h"
#include "syntac_error.h"
#include "conditio.h"
#include "sentense.h"

void whilesent(Token &token) {
    if (token.code == InnerCode::getInnerCode("WHILE")) {
        token = get_next_token();
    } else
        throw Syntax_Exception();
    conditio(token);
    if (token.code == InnerCode::getInnerCode("DO")) {
        token = get_next_token();
    } else
        throw Syntax_Exception();
    sentence(token);
}

#endif //COMPILERPRINCIPLES_WHILESENT_H
