#include "T100OrderDiv.h"

namespace T100QU32{

T100OrderDiv::T100OrderDiv(T100QU32* host, T100Executor32* exec)
    :T100Order(host, exec)
{
    //ctor
}

T100OrderDiv::~T100OrderDiv()
{
    //dtor
}

T100BOOL T100OrderDiv::run()
{
    getHost()->getAU32()->Div();
    return T100TRUE;
}

T100VOID T100OrderDiv::log()
{

}

}
