#include "T100Asm64LetterToken.h"

T100Asm64LetterToken::T100Asm64LetterToken()
    :T100Token()
{
    //ctor
}

T100Asm64LetterToken::~T100Asm64LetterToken()
{
    //dtor
}

T100VOID T100Asm64LetterToken::clear()
{
    T100Token::clear();
    value       = 0;
}
