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
    T100BOOL            result          = T100FALSE;
    T100WORD_BITS       order;

    order.WORD  = m_order;

    result = loadOperatorAllBuild(order.BYTE3.BYTE, target);

    if(result){
        T100WORD    base;
        T100WORD    ssr;
        T100WORD    spr;
        T100WORD    offset;
        T100WORD    value;

        base    = getHost()->getCU32()->getCBR();
        ssr     = getHost()->getCU32()->getSSR();
        spr     = getHost()->getCU32()->getSPR();

        if(0 < spr){
            spr--;
        }
        offset  = ssr + spr;

        result = getHost()->getMemory32()->read(offset, target.VALUE);

        if(result){
            result = setOperatorTarget(target);
        }

        if(result){
            getHost()->getCU32()->setSPR(spr);
        }
    }

    return result;
}

T100VOID T100OrderPop::log()
{

}

}
