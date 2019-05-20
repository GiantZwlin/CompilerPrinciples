//
// Created by memoria on 19-5-14.
//

#ifndef COMPILERPRINCIPLES_SUFFIX_H
#define COMPILERPRINCIPLES_SUFFIX_H

#include "../../Lexer/token.h"
#include "../../Lexer/innercode.h"
#include "utils.h"
#include "syntac_error.h"
#include "express.h"

void suffix(Token &token){
    if(token.code==InnerCode::getInnerCode(":")){
        token=get_next_token();
        if(token.code==InnerCode::getInnerCode("=")){
            token=get_next_token();
        }else
            throw Syntax_Exception();
        express(token);
    } else if(token.code==InnerCode::getInnerCode("("))
    {
        token=get_next_token();
        express(token);
        if(token.code==InnerCode::getInnerCode(")")){
            token=get_next_token();
        }else
            throw Syntax_Exception();
    } else
        return;
}
#endif //COMPILERPRINCIPLES_SUFFIX_H
