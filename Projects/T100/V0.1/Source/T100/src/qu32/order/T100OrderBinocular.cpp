#include "T100OrderBinocular.h"

#include "T100BitTypes.h"

namespace T100QU32{

T100OrderBinocular::T100OrderBinocular(T100QU32* host, T100Executor32* exec)
    :T100OrderDouble(host, exec)
{
    //ctor
}

T100OrderBinocular::~T100OrderBinocular()
{
    //dtor
}

T100BOOL T100OrderBinocular::loadBinocularBuild(T100SentenceBase::T100OPERATOR_BINOCULAR_BUILD& build)
{
    T100BOOL            result;
    T100WORD_BITS       order;

    order.WORD      = m_order;

    switch(order.BYTE1.BYTE){
    case T100SentenceBase::T100OPERATOR_NONE:
        {
            m_type      = T100SentenceBase::T100OPERATOR_NONE;
            return T100FALSE;
        }
        break;
    case T100SentenceBase::T100OPERATOR_ONE_ONE:
        {
            m_type      = T100SentenceBase::T100OPERATOR_ONE_ONE;

            build.TARGET.BASE.USED  = T100FALSE;
            build.SOURCE.BASE.USED  = T100FALSE;

            build.TARGET.OPERATOR.TYPE  = order.BYTE2.BYTE;
            build.SOURCE.OPERATOR.TYPE  = order.BYTE3.BYTE;
        }
        break;
    case T100SentenceBase::T100OPERATOR_THREE_THREE:
        {
            m_type      = T100SentenceBase::T100OPERATOR_THREE_THREE;

            build.TARGET.BASE.USED  = T100TRUE;
            build.SOURCE.BASE.USED  = T100TRUE;

            result = getAddrType(order.BYTE2.BYTE, build.TARGET.ADDR_TYPE);
            if(!result){
                return T100FALSE;
            }

            result = getAddrType(order.BYTE3.BYTE, build.SOURCE.ADDR_TYPE);
            if(!result){
                return T100FALSE;
            }

            order.WORD  = getHost()->getCU32()->step();

            build.TARGET.BASE.TYPE      = order.BYTE0.BYTE;
            build.TARGET.OPERATOR.TYPE  = order.BYTE1.BYTE;

            build.SOURCE.BASE.TYPE      = order.BYTE2.BYTE;
            build.SOURCE.OPERATOR.TYPE  = order.BYTE3.BYTE;
        }
        break;
    default:
        return T100FALSE;
    }
    return T100TRUE;
}

}
