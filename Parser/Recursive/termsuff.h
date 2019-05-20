//
// Created by memoria on 19-5-14.
//

#ifndef COMPILERPRINCIPLES_TERMSUFF_H
#define COMPILERPRINCIPLES_TERMSUFF_H

#include "../../Lexer/token.h"
#include "addoper.h"
#include "term.h"

void termsuff(Token &token) {
    if (token.code == InnerCode::getInnerCode("+") || token.code == InnerCode::getInnerCode("-"))
        addoper(token);
    term(token);
    termsuff(token);
    else
    return;
}

}

#endif //COMPILERPRINCIPLES_TERMSUFF_H
