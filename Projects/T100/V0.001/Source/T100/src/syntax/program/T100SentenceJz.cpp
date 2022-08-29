#include "T100SentenceJz.h"

#include "T100FileData.h"
#include "T100SentenceScan.h"


T100SentenceJz::T100SentenceJz(T100SentenceScan* scan)
    :T100Sentence(scan)
{
    //ctor
}

T100SentenceJz::~T100SentenceJz()
{
    //dtor
}

T100BOOL T100SentenceJz::parse()
{
    T100BOOL    result      = T100FALSE;

    setLoaded(T100FALSE);
    result = parseOperator(target);

    if(result){
        type            = T100SENTENCE_JZ;
        m_token->type   = T100SENTENCE_JZ;
    }

    return result;
}

T100BOOL T100SentenceJz::build(T100FileData* code)
{
    T100BOOL            result;
    T100WORD_BITS       order;
    T100OPERATOR_BUILD  info;

    order.BYTE0.BYTE = T100ORDER_JZ;

    info.BASE_USED  = T100FALSE;
    info.BASE_TYPE  = T_NONE;
    result = buildOperator(code, target, info);
    if(!result){
        T100Error::error(T100AssemblyHint::build_hint(type, data, T100BUILD_SENTENCE_ERROR));
        return T100FALSE;
    }

    code->setValue(order.WORD);
    code->next();

    code->setValue(info.OPERATOR_VALUE);
    code->next();

    return T100TRUE;
}
