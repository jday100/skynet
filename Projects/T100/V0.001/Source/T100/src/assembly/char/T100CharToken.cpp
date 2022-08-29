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
    data        = 0;
    bytes.clear();

    T100Token::clear();
}
