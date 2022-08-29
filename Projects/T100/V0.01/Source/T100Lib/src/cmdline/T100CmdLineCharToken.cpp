#include "T100CmdLineCharToken.h"

T100CmdLineCharToken::T100CmdLineCharToken()
{
    //ctor
}

T100CmdLineCharToken::~T100CmdLineCharToken()
{
    //dtor
}

T100VOID T100CmdLineCharToken::clear()
{
    value   = 0;

    exec.clear();

    T100Token::clear();
}
