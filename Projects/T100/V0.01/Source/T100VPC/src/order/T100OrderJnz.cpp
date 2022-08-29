#include "T100OrderJnz.h"

T100OrderJnz::T100OrderJnz(T100QU32* host, T100Executor32* exec)
    :T100Order(host, exec)
{
    //ctor
}

T100OrderJnz::~T100OrderJnz()
{
    //dtor
}

T100BOOL T100OrderJnz::run()
{
    T100WORD            offset;
    T100WORD            value;

    offset      = getHost()->getCU32()->step();
    value       = getHost()->getAU32()->getACR();

    if(0 != value){
        getHost()->getCU32()->setCOR(offset);
    }

    return T100TRUE;
}

T100VOID T100OrderJnz::log()
{

}
