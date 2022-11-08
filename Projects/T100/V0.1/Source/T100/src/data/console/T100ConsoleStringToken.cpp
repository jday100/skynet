#include "T100ConsoleStringToken.h"

namespace T100Library{

T100ConsoleStringToken::T100ConsoleStringToken()
    :T100Component::T100Token()
{
    //ctor
}

T100ConsoleStringToken::~T100ConsoleStringToken()
{
    //dtor
}

T100VOID T100ConsoleStringToken::clear()
{
    value.clear();

    T100Component::T100Token::clear();
}

}
