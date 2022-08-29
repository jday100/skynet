#include "T100SentenceJump.h"

#include "T100FileData.h"
#include "T100SentenceScan.h"


T100SentenceJump::T100SentenceJump(T100SentenceScan* scan)
    :T100Sentence(scan)
{
    //ctor
}

T100SentenceJump::~T100SentenceJump()
{
    //dtor
}

T100BOOL T100SentenceJump::parse()
{
    T100BOOL    result      = T100FALSE;

    setLoaded(T100FALSE);
    result = parseOperator(target);

    if(result){
        type            = T100SENTENCE_JUMP;
        m_token->type   = T100SENTENCE_JUMP;
    }

    return result;
}

T100BOOL T100SentenceJump::build(T100FileData* code)
{
    T100BOOL        result;
    T100WORD_BITS   order;

    order.BYTE0.BYTE = T100ORDER_JUMP;

    T100OPERATOR_BUILD  info;

    result = buildOperator(code, target, info);
    if(!result){
        T100Error::error(T100AssemblyHint::build_hint(type, data, T100BUILD_SENTENCE_ERROR));
        return T100FALSE;
    }

    order.BYTE1.BYTE = info.BASE_TYPE;
    order.BYTE2.BYTE = info.OPERATOR_TYPE;

    code->setValue(order.WORD);
    code->next();

    if(info.BASE_USED && info.BASE_FLAG){
        code->setValue(info.BASE_VALUE);
        code->next();
    }

    if(info.OPERATOR_FLAG){
        code->setValue(info.OPERATOR_VALUE);
        code->next();
    }

    return result;
}
