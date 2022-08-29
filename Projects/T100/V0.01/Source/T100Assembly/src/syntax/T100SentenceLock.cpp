#include "T100SentenceLock.h"

T100SentenceLock::T100SentenceLock(T100SentenceScanner* scanner)
    :T100Sentence(scanner)
{
    //ctor
}

T100SentenceLock::~T100SentenceLock()
{
    //dtor
}

T100BOOL T100SentenceLock::parse()
{
    T100BOOL        result          = T100TRUE;

    setLoaded(T100FALSE);

    if(result){
        type            = T100SENTENCE_LOCK;
        m_token->type   = T100SENTENCE_LOCK;
    }

    return result;
}

T100BOOL T100SentenceLock::build(T100BuildInfo* info)
{
    T100WORD_BITS   order;

    order.BYTE0.BYTE = T100ORDER_LOCK;

    info->setValue(order.WORD);
    info->next();

    return T100TRUE;
}
