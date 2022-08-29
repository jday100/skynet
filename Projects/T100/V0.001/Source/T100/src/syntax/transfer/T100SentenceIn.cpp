#include "T100SentenceIn.h"

#include "T100Order.h"
#include "T100FileData.h"
#include "T100SentenceScan.h"


T100SentenceIn::T100SentenceIn(T100SentenceScan* scan)
    :T100Sentence(scan)
{
    //ctor
}

T100SentenceIn::~T100SentenceIn()
{
    //dtor
}

T100BOOL T100SentenceIn::parse()
{
    T100BOOL    result      = T100FALSE;

    setLoaded(T100FALSE);
    result = parseComplexus(target);
    if(!result){
        T100Error::error(T100AssemblyHint::sentence_hint(this, T100SENTENCESCAN_SENTENCE_SYNTAX_ERROR));
        return T100FALSE;
    }

    result = parseOperator(source);

    if(result){
        type            = T100SENTENCE_IN;
        m_token->type   = T100SENTENCE_IN;
    }

    return result;
}

T100BOOL T100SentenceIn::build(T100FileData* code)
{
    T100BOOL            result      = T100FALSE;
    T100WORD_BITS       order;
    T100OPERATOR_INFO   info;

    switch(target.TYPE){
    case T100OPERATOR_ONE_ONE:
        {
            info.TARGET.OFFSET  = 0;
        }
        break;
    case T100OPERATOR_THREE_THREE:
        {
            info.TARGET.OFFSET  = 1;
        }
        break;
    default:
        info.TARGET.OFFSET = 0;
    }

    result = buildOperator(code, target, info.TARGET);
    if(!result){
        T100Error::error(T100AssemblyHint::build_hint(type, data, T100BUILD_SENTENCE_ERROR));
        return T100FALSE;
    };

    info.SOURCE.OFFSET      = info.TARGET.OFFSET;
    info.SOURCE.BASE_USED   = T100FALSE;
    info.SOURCE.BASE_TYPE   = T_NONE;
    result = buildOperator(code, source, info.SOURCE);
    if(!result){
        T100Error::error(T100AssemblyHint::build_hint(type, data, T100BUILD_SENTENCE_ERROR));
        return T100FALSE;
    };

    info.TYPE           = target.TYPE;

    result = buildInfo(T100ORDER_IN, code, info);
    if(!result){
        T100Error::error(T100AssemblyHint::build_hint(type, data, T100BUILD_SENTENCE_ERROR));
        return T100FALSE;
    }

    return result;

    /*
    T100BOOL            result      = T100FALSE;
    T100WORD_BITS       order;
    T100OPERATOR_INFO   info;

    result = buildOperator(code, target, info.TARGET);
    if(!result){
        T100Error::error(T100AssemblyHint::build_hint(type, data, T100BUILD_SENTENCE_ERROR));
        return T100FALSE;
    };

    info.SOURCE.OFFSET      = info.TARGET.OFFSET;
    info.SOURCE.BASE_USED   = T100FALSE;
    info.SOURCE.BASE_TYPE   = T_NONE;
    result = buildOperator(code, source, info.SOURCE);
    if(!result){
        T100Error::error(T100AssemblyHint::build_hint(type, data, T100BUILD_SENTENCE_ERROR));
        return T100FALSE;
    };

    order.BYTE0.BYTE    = T100ORDER_IN;
    order.BYTE1.BYTE    = info.TARGET.BASE_TYPE;
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
    }

    if(info.SOURCE.BASE_USED){
        T100Error::error(T100AssemblyHint::build_hint(type, data, T100BUILD_SENTENCE_ERROR));
        return T100FALSE;
    }

    if(info.SOURCE.OPERATOR_FLAG){
        code->setValue(info.SOURCE.OPERATOR_VALUE);
        code->next();
    }

    return T100TRUE;
    */
}
