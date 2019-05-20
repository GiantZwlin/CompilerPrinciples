//
// Created by memoria on 19-5-14.
//

#ifndef COMPILERPRINCIPLES_SENTSUFF_H
#define COMPILERPRINCIPLES_SENTSUFF_H

#include "../../Lexer/token.h"
#include "utils.h"
#include "../../Lexer/innercode.h"
#include "sentense.h"

void sentsuff(Token &token) {
    if (token.code == InnerCode::getInnerCode(";")) {
        token = get_next_token();
        sentence(token);
        sentsuff(token);
    } else
        return;
}

#endif //COMPILERPRINCIPLES_SENTSUFF_H
