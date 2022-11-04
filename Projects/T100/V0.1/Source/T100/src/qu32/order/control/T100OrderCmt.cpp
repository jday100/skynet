#include "T100OrderCmt.h"

namespace T100QU32{

T100OrderCmt::T100OrderCmt(T100QU32* host, T100Executor32* exec)
    :T100Order(host, exec)
{
    //ctor
}

T100OrderCmt::~T100OrderCmt()
{
    //dtor
}

T100BOOL T100OrderCmt::run()
{
    id = getHost()->getCU32()->step();

    getHost()->getExecutor32()->pauseComment();
    return T100TRUE;
}

T100VOID T100OrderCmt::log()
{

}

}
