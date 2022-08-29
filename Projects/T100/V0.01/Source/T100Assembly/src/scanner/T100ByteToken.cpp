#include "T100ByteToken.h"

T100ByteToken::T100ByteToken()
{
    //ctor
}

T100ByteToken::~T100ByteToken()
{
    //dtor
}

T100VOID T100ByteToken::clear()
{
    T100Token::clear();

    value       = 0;
}
