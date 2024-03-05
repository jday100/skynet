#include "T100Asm64SentenceToken.h"

T100Asm64SentenceToken::T100Asm64SentenceToken()
    :T100Token()
{
    //ctor
}

T100Asm64SentenceToken::~T100Asm64SentenceToken()
{
    //dtor
}

T100VOID T100Asm64SentenceToken::clear()
{
    T100Token::clear();
    value       = T100NULL;
}
