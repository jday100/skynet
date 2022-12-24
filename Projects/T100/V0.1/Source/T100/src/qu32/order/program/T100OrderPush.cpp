#include "T100OrderPush.h"

#include "T100BitTypes.h"

namespace T100QU32{

T100OrderPush::T100OrderPush(T100QU32* host, T100Executor32* exec)
    :T100OrderBase(host, exec)
{
    //ctor
}

T100OrderPush::~T100OrderPush()
{
    //dtor
}

T100BOOL T100OrderPush::run()
{
    return parsePushAllBuild();
}

T100VOID T100OrderPush::log()
{

}

}
