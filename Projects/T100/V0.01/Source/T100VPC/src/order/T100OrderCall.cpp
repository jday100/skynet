#include "T100OrderCall.h"

T100OrderCall::T100OrderCall(T100QU32* host, T100Executor32* exec)
    :T100Order(host, exec)
{
    //ctor
}

T100OrderCall::~T100OrderCall()
{
    //dtor
}

T100BOOL T100OrderCall::run()
{
    T100BOOL            result          = T100TRUE;

    result = loadMonoTarget(target);

    if(!result){
        return T100FALSE;
    }

    if(target.USED){
        getHost()->getInterrupt32()->call(target.BASE.VALUE, target.OPERATOR.VALUE);
    }else{
        getHost()->getInterrupt32()->call(target.OPERATOR.VALUE);
    }

    return T100TRUE;

}

T100VOID T100OrderCall::log()
{

}
