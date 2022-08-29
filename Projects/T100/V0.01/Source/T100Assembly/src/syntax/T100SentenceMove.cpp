#include "T100SentenceMove.h"

T100SentenceMove::T100SentenceMove(T100SentenceScanner* scanner)
    :T100Sentence(scanner)
{
    //ctor
}

T100SentenceMove::~T100SentenceMove()
{
    //dtor
}

T100BOOL T100SentenceMove::parse()
{
    T100BOOL        result          = T100TRUE;

    setLoaded(T100FALSE);
    result = parseOperator(ops);

    if(result){
        type            = T100SENTENCE_MOVE;
        m_token->type   = T100SENTENCE_MOVE;
    }

    return result;
}

T100BOOL T100SentenceMove::build(T100BuildInfo* info)
{
    T100BOOL                result      = T100FALSE;
    T100OPERATOR_INFO       build;

    result = buildOperator(info, ops, build);
    if(!result){
        //T100Error::error(T100AssemblyHint::build_hint(type, data, T100BUILD_SENTENCE_ERROR));
        return T100FALSE;
    }

    T100WORD_BITS   order;

    order.BYTE0.BYTE    = T100ORDER_MOVE;

    switch(build.TYPE){
    case T100OPERATOR_ONE_ONE:
        {
            order.BYTE1.BYTE    = T100OPERATOR_ONE_ONE;

            order.BYTE2.BYTE    = build.TARGET.OPERATOR_TYPE;
            order.BYTE3.BYTE    = build.SOURCE.OPERATOR_TYPE;

            info->setValue(order.WORD);
            info->next();

            if(build.TARGET.OPERATOR_FLAG){
                info->setValue(build.TARGET.OPERATOR_VALUE);
                info->next();

                if(build.TARGET.OPERATOR_ARRAY){
                    info->setValue(build.TARGET.OPERATOR_INDEX);
                    info->next();
                }
            }

            if(build.SOURCE.OPERATOR_FLAG){
                info->setValue(build.SOURCE.OPERATOR_VALUE);
                info->next();

                if(build.SOURCE.OPERATOR_ARRAY){
                    info->setValue(build.SOURCE.OPERATOR_INDEX);
                    info->next();
                }
            }
        }
        break;
    case T100OPERATOR_THREE_THREE:
        {
            order.BYTE1.BYTE    = T100OPERATOR_THREE_THREE;

            order.BYTE2.BYTE    = build.TARGET.TYPE;
            order.BYTE3.BYTE    = build.SOURCE.TYPE;

            info->setValue(order.WORD);
            info->next();

            order.BYTE0.BYTE    = build.TARGET.BASE_TYPE;
            order.BYTE1.BYTE    = build.TARGET.OPERATOR_TYPE;
            order.BYTE2.BYTE    = build.SOURCE.BASE_TYPE;
            order.BYTE3.BYTE    = build.SOURCE.OPERATOR_TYPE;

            info->setValue(order.WORD);
            info->next();

            if(build.TARGET.BASE_USED && build.TARGET.BASE_FLAG){
                info->setValue(build.TARGET.BASE_VALUE);
                info->next();
            }

            if(build.TARGET.OPERATOR_FLAG){
                info->setValue(build.TARGET.OPERATOR_VALUE);
                info->next();

                if(build.TARGET.OPERATOR_ARRAY){
                    info->setValue(build.TARGET.OPERATOR_INDEX);
                    info->next();
                }
            }

            if(build.SOURCE.BASE_USED && build.SOURCE.BASE_FLAG){
                info->setValue(build.SOURCE.BASE_VALUE);
                info->next();
            }

            if(build.SOURCE.OPERATOR_FLAG){
                info->setValue(build.SOURCE.OPERATOR_VALUE);
                info->next();

                if(build.SOURCE.OPERATOR_ARRAY){
                    info->setValue(build.SOURCE.OPERATOR_INDEX);
                    info->next();
                }
            }
        }
        break;
    default:
        return T100FALSE;
    }

    return result;
}
