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
    data    = 0;

    T100Token::clear();
}
