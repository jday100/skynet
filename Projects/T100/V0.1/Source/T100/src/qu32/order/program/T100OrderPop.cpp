#include "T100OrderPop.h"

namespace T100QU32{

T100OrderPop::T100OrderPop(T100QU32* host, T100Executor32* exec)
    :T100Order(host, exec)
{
    //ctor
}

T100OrderPop::~T100OrderPop()
{
    //dtor
}

T100BOOL T100OrderPop::run()
{
    return T100FALSE;
}

T100VOID T100OrderPop::log()
{

}

}
