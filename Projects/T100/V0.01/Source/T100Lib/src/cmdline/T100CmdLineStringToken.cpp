#include "T100CmdLineStringToken.h"

T100CmdLineStringToken::T100CmdLineStringToken()
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

    T100Token::clear();
}
