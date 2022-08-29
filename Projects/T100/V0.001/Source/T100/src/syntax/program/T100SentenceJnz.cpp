#include "T100SentenceJnz.h"

#include "T100FileData.h"
#include "T100SentenceScan.h"


T100SentenceJnz::T100SentenceJnz(T100SentenceScan* scan)
    :T100Sentence(scan)
{
    //ctor
}

T100SentenceJnz::~T100SentenceJnz()
{
    //dtor
}

T100BOOL T100SentenceJnz::parse()
{
    T100BOOL    result      = T100FALSE;

    setLoaded(T100FALSE);
    result = parseOperator(target);

    if(result){
        type            = T100SENTENCE_JNZ;
        m_token->type   = T100SENTENCE_JNZ;
    }

    return result;
}

T100BOOL T100SentenceJnz::build(T100FileData* code)
{
    T100WORD_BITS order;

    order.BYTE0.BYTE = T100ORDER_JNZ;

    T100OPERATOR_BUILD  info;

    buildOperator(code, target, info);

    code->setValue(order.WORD);
    code->next();

    code->setValue(info.OPERATOR_OFFSET);
    code->next();

    return T100TRUE;
}
