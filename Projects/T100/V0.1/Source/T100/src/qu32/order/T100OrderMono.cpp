#include "T100OrderMono.h"

#include "T100BitTypes.h"

namespace T100QU32{

T100OrderMono::T100OrderMono(T100QU32* host, T100Executor32* exec)
    :T100OrderComplexus(host, exec)
{
    //ctor
}

T100OrderMono::~T100OrderMono()
{
    //dtor
}

T100BOOL T100OrderMono::parseMonoBuild(T100SentenceBase::T100OPERATOR_COMPLEXUS_BUILD& build)
{
    T100BOOL            result;
    T100WORD_BITS       order;

    order.WORD          = m_order;

    build.BASE.TYPE     = order.BYTE2.BYTE;
    build.OPERATOR.TYPE = order.BYTE3.BYTE;

    result = parseComplexusBuild(build);

    return result;
}

}
