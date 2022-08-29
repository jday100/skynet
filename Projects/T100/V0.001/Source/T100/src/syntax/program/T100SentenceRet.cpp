#include "T100SentenceRet.h"

#include "T100FileData.h"
#include "T100SentenceScan.h"


T100SentenceRet::T100SentenceRet(T100SentenceScan* scan)
    :T100Sentence(scan)
{
    //ctor
}

T100SentenceRet::~T100SentenceRet()
{
    //dtor
}

T100BOOL T100SentenceRet::parse()
{
    T100BOOL    result      = T100TRUE;

    setLoaded(T100FALSE);

    if(result){
        type            = T100SENTENCE_RETURN;
        m_token->type   = T100SENTENCE_RETURN;
    }

    return result;
}

T100BOOL T100SentenceRet::build(T100FileData* code)
{
    T100WORD_BITS order;

    order.BYTE0.BYTE = T100ORDER_RETURN;

    code->setValue(order.WORD);
    code->next();

    return T100TRUE;
}
