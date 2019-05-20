//
// Created by memoria on 19-5-14.
//

#ifndef COMPILERPRINCIPLES_FACTSUFF_H
#define COMPILERPRINCIPLES_FACTSUFF_H

#include "../../Lexer/token.h"
#include "muloper.h"
#include "factor.h"

void factsuff(Token &token) {
    if (token.code==InnerCode::getInnerCode("*")||token.code==InnerCode::getInnerCode("/")) {
        muloper(token);
        factor(token);
        factsuff(token);
    } else return;
}

#endif //COMPILERPRINCIPLES_FACTSUFF_H
