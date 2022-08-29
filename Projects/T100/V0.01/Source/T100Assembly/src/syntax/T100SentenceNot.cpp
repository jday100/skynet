#include "T100SentenceNot.h"

T100SentenceNot::T100SentenceNot(T100SentenceScanner* scanner)
    :T100Sentence(scanner)
{
    //ctor
}

T100SentenceNot::~T100SentenceNot()
{
    //dtor
}

T100BOOL T100SentenceNot::parse()
{
    T100BOOL        result          = T100TRUE;

    setLoaded(T100FALSE);

    if(result){
        type            = T100SENTENCE_NOT;
        m_token->type   = T100SENTENCE_NOT;
    }

    return result;
}

T100BOOL T100SentenceNot::build(T100BuildInfo* info)
{
    T100WORD_BITS   order;

    order.BYTE0.BYTE = T100ORDER_NOT;

    info->setValue(order.WORD);
    info->next();

    return T100TRUE;
}
