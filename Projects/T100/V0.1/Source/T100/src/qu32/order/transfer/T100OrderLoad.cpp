#include "T100OrderLoad.h"

namespace T100QU32{

T100OrderLoad::T100OrderLoad(T100QU32* host, T100Executor32* exec)
    :T100Order(host, exec)
{
    //ctor
}

T100OrderLoad::~T100OrderLoad()
{
    //dtor
}

T100BOOL T100OrderLoad::run()
{
    return T100TRUE;
}

T100VOID T100OrderLoad::log()
{

}

}
