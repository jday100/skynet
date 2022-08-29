#include "T100CharToken.h"

T100CharToken::T100CharToken()
{
    //ctor
}

T100CharToken::~T100CharToken()
{
    //dtor
}

T100VOID T100CharToken::clear()
{
    T100Token::clear();

    value       = 0;
    //bytes.clear();
}
