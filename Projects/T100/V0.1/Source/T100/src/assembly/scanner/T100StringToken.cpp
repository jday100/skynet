#include "T100StringToken.h"

namespace T100Assembly{

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
    value.clear();

    T100Token::clear();
}

}
