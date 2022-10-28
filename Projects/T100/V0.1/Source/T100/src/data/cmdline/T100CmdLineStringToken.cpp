#include "T100CmdLineStringToken.h"

namespace T100Library{

T100CmdLineStringToken::T100CmdLineStringToken()
    :T100Component::T100Token()
{
    //ctor
}

T100CmdLineStringToken::~T100CmdLineStringToken()
{
    //dtor
}

T100VOID T100CmdLineStringToken::clear()
{
    value.clear();

    T100Component::T100Token::clear();
}

}
