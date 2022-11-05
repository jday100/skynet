#include "T100OrderCopy.h"

namespace T100QU32{

T100OrderCopy::T100OrderCopy(T100QU32* host, T100Executor32* exec)
    :T100Order(host, exec)
{
    //ctor
}

T100OrderCopy::~T100OrderCopy()
{
    //dtor
}

T100BOOL T100OrderCopy::run()
{
    return T100TRUE;
}

T100VOID T100OrderCopy::log()
{

}

}
