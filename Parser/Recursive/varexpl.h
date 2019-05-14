//
// Created by memoria on 19-5-14.
//

#ifndef COMPILERPRINCIPLES_VAREXPL_H
#define COMPILERPRINCIPLES_VAREXPL_H

#include "../../Lexer/token.h"
#include "../../Lexer/innercode.h"
#include "utils.h"
#include "vardefi.h"
#include "varsuff.h"

void varexpl(Token &token){
    if (token.code==InnerCode::getInnerCode("VAR")){
        token = get_next_token();
        vardefi(token);
        varsuff(token);
    }
}
#endif //COMPILERPRINCIPLES_VAREXPL_H
