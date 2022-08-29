#include "T100SentenceRet.h"

T100SentenceRet::T100SentenceRet(T100SentenceScanner* scanner)
    :T100Sentence(scanner)
{
    //ctor
}

T100SentenceRet::~T100SentenceRet()
{
    //dtor
}

T100BOOL T100SentenceRet::parse()
{
    T100BOOL        result          = T100TRUE;

    setLoaded(T100FALSE);

    if(result){
        type            = T100SENTENCE_RETURN;
        m_token->type   = T100SENTENCE_RETURN;
    }

    return result;
}

T100BOOL T100SentenceRet::build(T100BuildInfo* info)
{
    T100WORD_BITS   order;

    order.BYTE0.BYTE = T100ORDER_RETURN;

    info->setValue(order.WORD);
    info->next();

    return T100TRUE;
}
