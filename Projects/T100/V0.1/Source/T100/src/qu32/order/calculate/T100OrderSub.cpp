#include "T100OrderSub.h"

namespace T100QU32{

T100OrderSub::T100OrderSub(T100QU32* host, T100Executor32* exec)
    :T100Order(host, exec)
{
    //ctor
}

T100OrderSub::~T100OrderSub()
{
    //dtor
}

T100BOOL T100OrderSub::run()
{
    getHost()->getAU32()->Sub();
    return T100TRUE;
}

T100VOID T100OrderSub::log()
{

}

}
