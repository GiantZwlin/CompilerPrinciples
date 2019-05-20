//
// Created by memoria on 19-5-14.
//

#ifndef COMPILERPRINCIPLES_TERM_H
#define COMPILERPRINCIPLES_TERM_H

#include "../../Lexer/token.h"
#include "factor.h"
#include "factsuff.h"

void term(Token &token) {
    factor(token);
    factsuff(token);
}

#endif //COMPILERPRINCIPLES_TERM_H
