#include "T100OrderEnter.h"

namespace T100QU32{

T100OrderEnter::T100OrderEnter(T100QU32* host, T100Executor32* exec)
    :T100OrderBase(host, exec)
{
    //ctor
}

T100OrderEnter::~T100OrderEnter()
{
    //dtor
}

T100BOOL T100OrderEnter::run()
{
    T100BOOL        result          = T100TRUE;

    result = parseMonoBuild(target);
    if(!result){
        return T100FALSE;
    }

    result = getGdt()->enter(target.BASE.VALUE, target.OPERATOR.VALUE);

    return result;
}

T100VOID T100OrderEnter::log()
{

}

}
