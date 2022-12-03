#include "T100OrderComplexus.h"

namespace T100QU32{

T100OrderComplexus::T100OrderComplexus(T100QU32* host, T100Executor32* exec)
    :T100OrderAll(host, exec)
{
    //ctor
}

T100OrderComplexus::~T100OrderComplexus()
{
    //dtor
}

T100BOOL T100OrderComplexus::parseComplexusBuild(T100SentenceBase::T100OPERATOR_COMPLEXUS_BUILD& build)
{
    T100BOOL        result          = T100TRUE;

    result = loadComplexusBuild(build);
    if(!result){
        return T100FALSE;
    }

    result = getComplexusBuild(build);

    return result;
}

T100BOOL T100OrderComplexus::loadComplexusBuild(T100SentenceBase::T100OPERATOR_COMPLEXUS_BUILD& build)
{
    T100BOOL        result;

    result = loadOperatorBuild(build.BASE.TYPE, build.BASE);
    if(!result){
        return T100FALSE;
    }

    result = loadOperatorBuild(build.OPERATOR.TYPE, build.OPERATOR);

    return result;
}

T100BOOL T100OrderComplexus::getComplexusBuild(T100SentenceBase::T100OPERATOR_COMPLEXUS_BUILD& build)
{
    T100BOOL        result;

    result = getOperatorSource(build.BASE);
    if(!result){
        return T100FALSE;
    }

    result = getOperatorSource(build.OPERATOR);

    return result;
}

}
