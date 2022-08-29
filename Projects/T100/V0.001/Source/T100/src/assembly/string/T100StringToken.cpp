#include "T100StringToken.h"

T100StringToken::T100StringToken()
{
    //ctor
}

T100StringToken::~T100StringToken()
{
    //dtor
}

T100VOID T100StringToken::clear()
{
    data.clear();
    bytes.clear();

    T100Token::clear();
}
