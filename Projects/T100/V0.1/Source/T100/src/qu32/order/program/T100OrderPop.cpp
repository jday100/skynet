#include "T100OrderPop.h"

#include "T100BitTypes.h"

namespace T100QU32{

T100OrderPop::T100OrderPop(T100QU32* host, T100Executor32* exec)
    :T100OrderBase(host, exec)
{
    //ctor
}

T100OrderPop::~T100OrderPop()
{
    //dtor
}

T100BOOL T100OrderPop::run()
{
    return parsePopAllBuild();
}

T100VOID T100OrderPop::log()
{

}

}
