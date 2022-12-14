#include "T100OrderLock.h"

namespace T100QU32{

T100OrderLock::T100OrderLock(T100QU32* host, T100Executor32* exec)
    :T100Order(host, exec)
{
    //ctor
}

T100OrderLock::~T100OrderLock()
{
    //dtor
}

T100BOOL T100OrderLock::run()
{
    getHost()->getInterrupt32()->lock();
    return T100TRUE;
}

T100VOID T100OrderLock::log()
{

}

}
