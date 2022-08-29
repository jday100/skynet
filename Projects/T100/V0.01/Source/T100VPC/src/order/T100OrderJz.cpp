#include "T100OrderJz.h"

T100OrderJz::T100OrderJz(T100QU32* host, T100Executor32* exec)
    :T100Order(host, exec)
{
    //ctor
}

T100OrderJz::~T100OrderJz()
{
    //dtor
}

T100BOOL T100OrderJz::run()
{
    T100WORD            offset;
    T100WORD            value;

    offset      = getHost()->getCU32()->step();
    value       = getHost()->getAU32()->getACR();

    if(0 == value){
        getHost()->getCU32()->setCOR(offset);
    }

    return T100TRUE;
}

T100VOID T100OrderJz::log()
{

}
