//
// Created by memoria on 19-5-14.
//

#ifndef COMPILERPRINCIPLES_IFSENT_H
#define COMPILERPRINCIPLES_IFSENT_H

#include "../../Lexer/token.h"
#include "../../Lexer/innercode.h"
#include "utils.h"
#include "syntac_error.h"
#include "conditio.h"
#include "sentense.h"

void ifsent(Token &token) {
    if (token.code == InnerCode::getInnerCode("IF")) {
        token = get_next_token();
    } else
        throw Syntax_Exception();
    conditio(token);
    if (token.code == InnerCode::getInnerCode("THEN")) {
        token = get_next_token();
    } else
        throw Syntax_Exception();
    sentence(token);
}

#endif //COMPILERPRINCIPLES_IFSENT_H
