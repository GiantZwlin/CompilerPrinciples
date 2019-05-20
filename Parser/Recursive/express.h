//
// Created by memoria on 19-5-14.
//

#ifndef COMPILERPRINCIPLES_EXPRESS_H
#define COMPILERPRINCIPLES_EXPRESS_H

#include "../../Lexer/token.h"
#include "../../Lexer/innercode.h"
#include "term.h"
#include "utils.h"
#include "termsuff.h"

void express(Token &token){
    if (token.code == InnerCode::getInnerCode("+")||token.code==InnerCode::getInnerCode("-")) {
        token = get_next_token();
    }
    term(token);
    termsuff(token);

}
#endif //COMPILERPRINCIPLES_EXPRESS_H
