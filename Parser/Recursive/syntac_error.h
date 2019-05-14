//
// Created by memoria on 19-5-14.
//

#ifndef COMPILERPRINCIPLES_SYNTAC_ERROR_H
#define COMPILERPRINCIPLES_SYNTAC_ERROR_H
#include<exception>
struct Syntax_Exception : public std::exception
{
    const char * what () const noexcept override
    {
        return "Syntax Error";
    }
};
#endif //COMPILERPRINCIPLES_SYNTAC_ERROR_H
