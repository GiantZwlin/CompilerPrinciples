//
// Created by memoria on 19-5-14.
//

#ifndef COMPILERPRINCIPLES_UTILS_H
#define COMPILERPRINCIPLES_UTILS_H

#include "../../Lexer/token.h"

static int now_token = 0;

Token get_next_token() {
    return Token("NONE", -1);
}


#endif //COMPILERPRINCIPLES_UTILS_H
