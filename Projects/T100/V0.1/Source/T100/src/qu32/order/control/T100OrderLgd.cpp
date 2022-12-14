#include "T100OrderLgd.h"

namespace T100QU32{

T100OrderLgd::T100OrderLgd(T100QU32* host, T100Executor32* exec)
    :T100OrderBase(host, exec)
{
    //ctor
}

T100OrderLgd::~T100OrderLgd()
{
    //dtor
}

T100BOOL T100OrderLgd::run()
{
    T100BOOL        result;

    result = parseMonoBuild(target);

    if(result){
        result = getHost()->getGdt32()->load(target.BASE.VALUE, target.OPERATOR.VALUE);
    }
    return result;
}

T100VOID T100OrderLgd::log()
{

}

}
