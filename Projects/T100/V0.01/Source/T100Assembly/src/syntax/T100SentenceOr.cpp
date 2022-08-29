#include "T100SentenceOr.h"

T100SentenceOr::T100SentenceOr(T100SentenceScanner* scanner)
    :T100Sentence(scanner)
{
    //ctor
}

T100SentenceOr::~T100SentenceOr()
{
    //dtor
}

T100BOOL T100SentenceOr::parse()
{
    T100BOOL        result          = T100TRUE;

    setLoaded(T100FALSE);

    if(result){
        type            = T100SENTENCE_OR;
        m_token->type   = T100SENTENCE_OR;
    }

    return result;
}

T100BOOL T100SentenceOr::build(T100BuildInfo* info)
{
    T100WORD_BITS   order;

    order.BYTE0.BYTE = T100ORDER_OR;

    info->setValue(order.WORD);
    info->next();

    return T100TRUE;
}
