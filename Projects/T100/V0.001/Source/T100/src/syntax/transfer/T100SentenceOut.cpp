#include "T100SentenceOut.h"

#include "T100Order.h"
#include "T100FileData.h"
#include "T100SentenceScan.h"


T100SentenceOut::T100SentenceOut(T100SentenceScan* scan)
    :T100Sentence(scan)
{
    //ctor
}

T100SentenceOut::~T100SentenceOut()
{
    //dtor
}

T100BOOL T100SentenceOut::parse()
{
    T100BOOL    result      = T100FALSE;

    setLoaded(T100FALSE);
    result = parseOperator(target);
    if(!result){
        T100Error::error(T100AssemblyHint::sentence_hint(this, T100SENTENCESCAN_SENTENCE_SYNTAX_ERROR));
        return T100FALSE;
    }

    result = parseComplexus(source);

    if(result){
        type            = T100SENTENCE_OUT;
        m_token->type   = T100SENTENCE_OUT;
    }

    return result;
}

T100BOOL T100SentenceOut::build(T100FileData* code)
{
    T100BOOL                result      = T100FALSE;
    T100OPERATOR_INFO       info;

    switch(source.TYPE){
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

    info.TARGET.BASE_USED   = T100FALSE;
    info.TARGET.BASE_TYPE   = T_NONE;
    result = buildOperator(code, target, info.TARGET);
    if(!result){
        T100Error::error(T100AssemblyHint::build_hint(type, data, T100BUILD_SENTENCE_ERROR));
        return T100FALSE;
    }

    info.SOURCE.OFFSET  = info.TARGET.OFFSET;
    result = buildComplexus(code, source, info.SOURCE);
    if(!result){
        T100Error::error(T100AssemblyHint::build_hint(type, data, T100BUILD_SENTENCE_ERROR));
        return T100FALSE;
    }

    info.TYPE           = source.TYPE;

    result = buildInfo(T100ORDER_OUT, code, info);
    if(!result){
        T100Error::error(T100AssemblyHint::build_hint(type, data, T100BUILD_SENTENCE_ERROR));
        return T100FALSE;
    }

    return result;

    /*
    T100BOOL            result      = T100FALSE;
    T100WORD_BITS       order;
    T100OPERATOR_INFO   info;

    info.TARGET.BASE_USED   = T100FALSE;
    info.TARGET.BASE_TYPE   = T_NONE;
    result = buildOperator(code, target, info.TARGET);
    if(!result){
        T100Error::error(T100AssemblyHint::build_hint(type, data, T100BUILD_SENTENCE_ERROR));
        return T100FALSE;
    }

    info.SOURCE.OFFSET  = info.TARGET.OFFSET;
    result = buildComplexus(code, source, info.SOURCE);
    if(!result){
        T100Error::error(T100AssemblyHint::build_hint(type, data, T100BUILD_SENTENCE_ERROR));
        return T100FALSE;
    }

    order.BYTE0.BYTE    = T100ORDER_OUT;
    order.BYTE1.BYTE    = info.TARGET.OPERATOR_TYPE;
    order.BYTE2.BYTE    = info.SOURCE.BASE_TYPE;
    order.BYTE3.BYTE    = info.SOURCE.OPERATOR_TYPE;

    code->setValue(order.WORD);
    code->next();

    if(info.TARGET.BASE_USED){
        T100Error::error(T100AssemblyHint::build_hint(type, data, T100BUILD_SENTENCE_ERROR));
        return T100FALSE;
    }

    if(info.TARGET.OPERATOR_FLAG){
        code->setValue(info.TARGET.OPERATOR_VALUE);
        code->next();
    }

    if(info.SOURCE.BASE_USED && info.SOURCE.BASE_FLAG){
        code->setValue(info.SOURCE.BASE_VALUE);
        code->next();
    }

    if(info.SOURCE.OPERATOR_FLAG){
        code->setValue(info.SOURCE.OPERATOR_VALUE);
        code->next();
    }

    return T100TRUE;
    */
}
