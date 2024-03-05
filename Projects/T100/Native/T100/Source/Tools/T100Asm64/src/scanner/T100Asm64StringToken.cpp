#include "T100Asm64StringToken.h"

T100Asm64StringToken::T100Asm64StringToken()
    :T100Token()
{
    //ctor
}

T100Asm64StringToken::~T100Asm64StringToken()
{
    //dtor
}

T100VOID T100Asm64StringToken::clear()
{
    T100Token::clear();
    value       = L"";
}
