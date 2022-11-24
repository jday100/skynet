#include "T100OrderPush.h"

namespace T100QU32{

T100OrderPush::T100OrderPush(T100QU32* host, T100Executor32* exec)
    :T100Order(host, exec)
{
    //ctor
}

T100OrderPush::~T100OrderPush()
{
    //dtor
}

T100BOOL T100OrderPush::run()
{

    return T100FALSE;
}

T100VOID T100OrderPush::log()
{

}

}
