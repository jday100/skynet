#include "T100Asm64FunctionToken.h"

T100Asm64FunctionToken::T100Asm64FunctionToken()
    :T100Token()
{
    //ctor
}

T100Asm64FunctionToken::~T100Asm64FunctionToken()
{
    //dtor
}

T100VOID T100Asm64FunctionToken::clear()
{
    T100Token::clear();
    name        = L"";
    value.clear();
}
