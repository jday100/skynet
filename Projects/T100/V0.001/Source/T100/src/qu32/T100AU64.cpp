#include "T100AU64.h"

T100AU64::T100AU64(T100QU32* host)
    :m_host(host), IAU((IComputer*)host)
{
    //ctor
}

T100AU64::~T100AU64()
{
    //dtor
}
