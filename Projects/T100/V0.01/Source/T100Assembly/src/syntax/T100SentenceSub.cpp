#include "T100SentenceSub.h"

T100SentenceSub::T100SentenceSub(T100SentenceScanner* scanner)
    :T100Sentence(scanner)
{
    //ctor
}

T100SentenceSub::~T100SentenceSub()
{
    //dtor
}

T100BOOL T100SentenceSub::parse()
{
    T100BOOL        result          = T100TRUE;

    setLoaded(T100FALSE);

    if(result){
        type            = T100SENTENCE_SUB;
        m_token->type   = T100SENTENCE_SUB;
    }

    return result;
}

T100BOOL T100SentenceSub::build(T100BuildInfo* info)
{
    T100WORD_BITS   order;

    order.BYTE0.BYTE = T100ORDER_SUB;

    info->setValue(order.WORD);
    info->next();

    return T100TRUE;
}
