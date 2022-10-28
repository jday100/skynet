#include "T100CmdLineCharToken.h"

namespace T100Library{

T100CmdLineCharToken::T100CmdLineCharToken()
    :T100Component::T100Token()
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

    T100Component::T100Token::clear();
}

}
