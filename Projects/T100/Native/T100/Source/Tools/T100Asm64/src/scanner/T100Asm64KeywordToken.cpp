#include "T100Asm64KeywordToken.h"

T100Asm64KeywordToken::T100Asm64KeywordToken()
    :T100Token()
{
    //ctor
}

T100Asm64KeywordToken::~T100Asm64KeywordToken()
{
    //dtor
}

T100VOID T100Asm64KeywordToken::clear()
{
    T100Token::clear();
    value       = L"";
}
