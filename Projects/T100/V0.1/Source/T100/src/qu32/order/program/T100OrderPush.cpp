#include "T100OrderPush.h"

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
    T100BOOL        result          = T100FALSE;

    result = loadOperatorAllBuild(target);

    if(result){
        result = getOperatorSource(target);
    }

    if(result){
        T100WORD    base;
        T100WORD    ssr;
        T100WORD    spr;
        T100WORD    offset;
        T100WORD    value;

        base    = getHost()->getCU32()->getCBR();
        ssr     = getHost()->getCU32()->getSSR();
        spr     = getHost()->getCU32()->getSPR();

        offset  = ssr + spr;

        getHost()->getMemory32()->write(offset, target.VALUE);
        spr++;
        getHost()->getCU32()->setSPR(spr);
        result = T100TRUE;
    }

    return result;
}

T100VOID T100OrderPush::log()
{

}

}
