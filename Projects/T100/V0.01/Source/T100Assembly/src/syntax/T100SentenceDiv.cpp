#include "T100SentenceDiv.h"

T100SentenceDiv::T100SentenceDiv(T100SentenceScanner* scanner)
    :T100Sentence(scanner)
{
    //ctor
}

T100SentenceDiv::~T100SentenceDiv()
{
    //dtor
}

T100BOOL T100SentenceDiv::parse()
{
    T100BOOL        result          = T100TRUE;

    setLoaded(T100FALSE);

    if(result){
        type            = T100SENTENCE_DIV;
        m_token->type   = T100SENTENCE_DIV;
    }

    return result;
}

T100BOOL T100SentenceDiv::build(T100BuildInfo* info)
{
    T100WORD_BITS   order;

    order.BYTE0.BYTE = T100ORDER_DIV;

    info->setValue(order.WORD);
    info->next();

    return T100TRUE;
}
