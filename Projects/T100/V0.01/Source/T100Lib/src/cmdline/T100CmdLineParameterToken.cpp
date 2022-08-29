#include "T100CmdLineParameterToken.h"

T100CmdLineParameterToken::T100CmdLineParameterToken()
{
    //ctor
}

T100CmdLineParameterToken::~T100CmdLineParameterToken()
{
    //dtor
}

T100VOID T100CmdLineParameterToken::clear()
{
    value = T100NULL;

    T100Token::clear();
}
