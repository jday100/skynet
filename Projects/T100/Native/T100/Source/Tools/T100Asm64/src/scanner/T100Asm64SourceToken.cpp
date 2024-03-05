#include "T100Asm64SourceToken.h"

T100Asm64SourceToken::T100Asm64SourceToken()
    :T100Token()
{
    //ctor
}

T100Asm64SourceToken::~T100Asm64SourceToken()
{
    //dtor
}

T100VOID T100Asm64SourceToken::clear()
{
    T100Token::clear();
    name        = L"";
    value.clear();
}
