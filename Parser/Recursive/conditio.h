//
// Created by memoria on 19-5-14.
//

#ifndef COMPILERPRINCIPLES_CONDITIO_H
#define COMPILERPRINCIPLES_CONDITIO_H

#include "../../Lexer/token.h"
#include "express.h"
#include "respoper.h"
#include "syntac_error.h"
#include "../../Lexer/innercode.h"
#include "utils.h"

void conditio(Token &token) {
    if (token.code == InnerCode::getInnerCode("ODD")) {
        token = get_next_token();
        express(token);
    } else {
        express(token);
        respoper(token);
        express(token);
    }
}

#endif //COMPILERPRINCIPLES_CONDITIO_H
