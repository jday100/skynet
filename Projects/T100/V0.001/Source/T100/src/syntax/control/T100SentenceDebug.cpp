#include "T100SentenceDebug.h"

#include "T100FileData.h"
#include "T100SentenceScan.h"


T100SentenceDebug::T100SentenceDebug(T100SentenceScan* scan)
    :T100Sentence(scan)
{
    //ctor
}

T100SentenceDebug::~T100SentenceDebug()
{
    //dtor
}

T100BOOL T100SentenceDebug::parse()
{
    T100BOOL    result      = T100TRUE;

    setLoaded(T100FALSE);

    if(result){
        type            = T100SENTENCE_DEBUG;
        m_token->type   = T100SENTENCE_DEBUG;
    }

    return result;
}

T100BOOL T100SentenceDebug::build(T100FileData* code)
{
    T100WORD_BITS order;

    order.BYTE0.BYTE = T100ORDER_DBG;

    code->setValue(order.WORD);
    code->next();

    return T100TRUE;
}
