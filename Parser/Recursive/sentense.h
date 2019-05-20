//
// Created by memoria on 19-5-14.
//

#ifndef COMPILERPRINCIPLES_SENTENSE_H
#define COMPILERPRINCIPLES_SENTENSE_H

#include "../../Lexer/token.h"
#include "../../Lexer/innercode.h"
#include "assipro.h"
#include "ifsent.h"

void sentence(Token &token){
if(token.code == InnerCode::getInnerCode("IDENTIFIER"))
assipro(token);
else if(token.code == InnerCode::getInnerCode("IF"))
    ifsent(token);
else if(token.code == InnerCode::getInnerCode("WHILE"))
    whilesent(token);
else if(token.code == InnerCode::getInnerCode("READ"))
    read(token);
else if(token.code == InnerCode::getInnerCode("WRITE"))
    write(token);
else if(token.code == InnerCode::getInnerCode("BEGIN"))
    compsent(token);
else
    return;
}
#endif //COMPILERPRINCIPLES_SENTENSE_H
