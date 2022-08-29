#include "T100SentenceLock.h"

#include "T100FileData.h"
#include "T100SentenceScan.h"


T100SentenceLock::T100SentenceLock(T100SentenceScan* scan)
    :T100Sentence(scan)
{
    //ctor
}

T100SentenceLock::~T100SentenceLock()
{
    //dtor
}

T100BOOL T100SentenceLock::parse()
{
    T100BOOL    result      = T100TRUE;

    setLoaded(T100FALSE);

    if(result){
        type            = T100SENTENCE_LOCK;
        m_token->type   = T100SENTENCE_LOCK;
    }

    return result;
}

T100BOOL T100SentenceLock::build(T100FileData* code)
{
    T100WORD_BITS order;

    order.BYTE0.BYTE = T100ORDER_LOCK;

    code->setValue(order.WORD);
    code->next();

    return T100TRUE;
}
