#include "T100CharToken.h"

namespace T100Assembly{

T100CharToken::T100CharToken()
    :T100Component::T100Token()
{
    //ctor
}

T100CharToken::~T100CharToken()
{
    //dtor
}

T100VOID T100CharToken::clear()
{
    value       = 0;
    T100Token::clear();
}

}
