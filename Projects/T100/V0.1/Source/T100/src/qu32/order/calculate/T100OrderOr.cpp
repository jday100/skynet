#include "T100OrderOr.h"

namespace T100QU32{

T100OrderOr::T100OrderOr(T100QU32* host, T100Executor32* exec)
    :T100Order(host, exec)
{
    //ctor
}

T100OrderOr::~T100OrderOr()
{
    //dtor
}

T100BOOL T100OrderOr::run()
{
    getHost()->getAU32()->Or();
    return T100TRUE;
}

T100VOID T100OrderOr::log()
{

}

}
