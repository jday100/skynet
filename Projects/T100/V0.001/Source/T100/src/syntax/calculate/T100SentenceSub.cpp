#include "T100SentenceSub.h"

#include "T100FileData.h"
#include "T100SentenceScan.h"


T100SentenceSub::T100SentenceSub(T100SentenceScan* scan)
    :T100Sentence(scan)
{
    //ctor
}

T100SentenceSub::~T100SentenceSub()
{
    //dtor
}

T100BOOL T100SentenceSub::parse()
{
    T100BOOL    result      = T100TRUE;

    setLoaded(T100FALSE);

    if(result){
        type            = T100SENTENCE_SUB;
        m_token->type   = T100SENTENCE_SUB;
    }

    return result;
}

T100BOOL T100SentenceSub::build(T100FileData* code)
{
    T100WORD_BITS order;

    order.BYTE0.BYTE = T100ORDER_SUB;

    code->setValue(order.WORD);
    code->next();

    return T100TRUE;
}
