#include "T100SentenceMove.h"

#include "T100Order.h"
#include "T100FileData.h"
#include "T100SentenceScan.h"


T100SentenceMove::T100SentenceMove(T100SentenceScan* scan)
    :T100Sentence(scan)
{
    //ctor
}

T100SentenceMove::~T100SentenceMove()
{
    //dtor
}

T100BOOL T100SentenceMove::parse()
{
    T100BOOL    result      = T100FALSE;

    setLoaded(T100FALSE);
    result = parseOperator(ops);

    if(result){
        type            = T100SENTENCE_MOVE;
        m_token->type   = T100SENTENCE_MOVE;
    }

    return result;
}

/*
T100BOOL T100SentenceMove::build(T100FileData* code)
{
    T100BOOL                result      = T100FALSE;
    T100Order               order;
    T100OPERATOR_INFO       info;

    result = buildOperator(code, ops, info);
    if(!result){
        T100Error::error(T100AssemblyHint::build_hint(type, data, T100BUILD_SENTENCE_ERROR));
        return T100FALSE;
    }

    order.setOrder(T100ORDER_MOVE);

    order.setTargetBaseType(info.TARGET.BASE_TYPE);
    order.setTargetOffsetType(info.TARGET.OPERATOR_TYPE);

    order.setSourceBaseType(info.SOURCE.BASE_TYPE);
    order.setSourceOffsetType(info.SOURCE.OPERATOR_TYPE);
    //
    code->setValue(order.getWORD());
    code->next();

    if(info.TARGET.BASE_USED && info.TARGET.BASE_FLAG){
        code->setValue(info.TARGET.BASE_VALUE);
        code->next();
    }

    if(info.TARGET.OPERATOR_FLAG){
        code->setValue(info.TARGET.OPERATOR_VALUE);
        code->next();

        if(info.TARGET.OPERATOR_ARRAY){
            code->setValue(info.TARGET.OPERATOR_INDEX);
            code->next();
        }
    }

    if(info.SOURCE.BASE_USED && info.SOURCE.BASE_FLAG){
        code->setValue(info.SOURCE.BASE_VALUE);
        code->next();
    }

    if(info.SOURCE.OPERATOR_FLAG){
        code->setValue(info.SOURCE.OPERATOR_VALUE);
        code->next();

        if(info.SOURCE.OPERATOR_ARRAY){
            code->setValue(info.SOURCE.OPERATOR_INDEX);
            code->next();
        }
    }

    return result;
}
*/

T100BOOL T100SentenceMove::build(T100FileData* code)
{
    T100BOOL                result      = T100FALSE;
    T100OPERATOR_INFO       info;

    result = buildOperator(code, ops, info);
    if(!result){
        T100Error::error(T100AssemblyHint::build_hint(type, data, T100BUILD_SENTENCE_ERROR));
        return T100FALSE;
    }

    T100WORD_BITS   order;

    order.BYTE0.BYTE    = T100ORDER_MOVE;

    switch(info.TYPE){
    case T100OPERATOR_ONE_ONE:
        {
            order.BYTE1.BYTE    = T100OPERATOR_ONE_ONE;

            order.BYTE2.BYTE    = info.TARGET.OPERATOR_TYPE;
            order.BYTE3.BYTE    = info.SOURCE.OPERATOR_TYPE;

            code->setValue(order.WORD);
            code->next();

            if(info.TARGET.OPERATOR_FLAG){
                code->setValue(info.TARGET.OPERATOR_VALUE);
                code->next();

                if(info.TARGET.OPERATOR_ARRAY){
                    code->setValue(info.TARGET.OPERATOR_INDEX);
                    code->next();
                }
            }

            if(info.SOURCE.OPERATOR_FLAG){
                code->setValue(info.SOURCE.OPERATOR_VALUE);
                code->next();

                if(info.SOURCE.OPERATOR_ARRAY){
                    code->setValue(info.SOURCE.OPERATOR_INDEX);
                    code->next();
                }
            }
        }
        break;
    case T100OPERATOR_THREE_THREE:
        {
            order.BYTE1.BYTE    = T100OPERATOR_THREE_THREE;

            order.BYTE2.BYTE    = info.TARGET.TYPE;
            order.BYTE3.BYTE    = info.SOURCE.TYPE;

            code->setValue(order.WORD);
            code->next();

            order.BYTE0.BYTE    = info.TARGET.BASE_TYPE;
            order.BYTE1.BYTE    = info.TARGET.OPERATOR_TYPE;
            order.BYTE2.BYTE    = info.SOURCE.BASE_TYPE;
            order.BYTE3.BYTE    = info.SOURCE.OPERATOR_TYPE;

            code->setValue(order.WORD);
            code->next();

            if(info.TARGET.BASE_USED && info.TARGET.BASE_FLAG){
                code->setValue(info.TARGET.BASE_VALUE);
                code->next();
            }

            if(info.TARGET.OPERATOR_FLAG){
                code->setValue(info.TARGET.OPERATOR_VALUE);
                code->next();

                if(info.TARGET.OPERATOR_ARRAY){
                    code->setValue(info.TARGET.OPERATOR_INDEX);
                    code->next();
                }
            }

            if(info.SOURCE.BASE_USED && info.SOURCE.BASE_FLAG){
                code->setValue(info.SOURCE.BASE_VALUE);
                code->next();
            }

            if(info.SOURCE.OPERATOR_FLAG){
                code->setValue(info.SOURCE.OPERATOR_VALUE);
                code->next();

                if(info.SOURCE.OPERATOR_ARRAY){
                    code->setValue(info.SOURCE.OPERATOR_INDEX);
                    code->next();
                }
            }
        }
        break;
    default:
        return T100FALSE;
    }

    return result;
}
