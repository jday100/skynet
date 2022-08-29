#include "T100SentenceUnlock.h"

#include "T100FileData.h"
#include "T100SentenceScan.h"


T100SentenceUnlock::T100SentenceUnlock(T100SentenceScan* scan)
    :T100Sentence(scan)
{
    //ctor
}

T100SentenceUnlock::~T100SentenceUnlock()
{
    //dtor
}

T100BOOL T100SentenceUnlock::parse()
{
    T100BOOL    result      = T100TRUE;

    setLoaded(T100FALSE);

    if(result){
        type            = T100SENTENCE_UNLOCK;
        m_token->type   = T100SENTENCE_UNLOCK;
    }

    return result;
}

T100BOOL T100SentenceUnlock::build(T100FileData* code)
{
    T100WORD_BITS order;

    order.BYTE0.BYTE = T100ORDER_UNLOCK;

    code->setValue(order.WORD);
    code->next();

    return T100TRUE;
}
