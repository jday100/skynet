#include "T100OrderRet.h"

namespace T100QU32{

T100OrderRet::T100OrderRet(T100QU32* host, T100Executor32* exec)
    :T100Order(host, exec)
{
    //ctor
}

T100OrderRet::~T100OrderRet()
{
    //dtor
}

T100BOOL T100OrderRet::run()
{
    getHost()->getInterrupt32()->ret();
    getHost()->getExecutor32()->pauseReturn();
    return T100TRUE;
}

T100VOID T100OrderRet::log()
{

}

}
