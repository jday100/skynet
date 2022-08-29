#include "T100SentenceXor.h"

T100SentenceXor::T100SentenceXor(T100SentenceScanner* scanner)
    :T100Sentence(scanner)
{
    //ctor
}

T100SentenceXor::~T100SentenceXor()
{
    //dtor
}

T100BOOL T100SentenceXor::parse()
{
    T100BOOL        result          = T100TRUE;

    setLoaded(T100FALSE);

    if(result){
        type            = T100SENTENCE_XOR;
        m_token->type   = T100SENTENCE_XOR;
    }

    return result;
}

T100BOOL T100SentenceXor::build(T100BuildInfo* info)
{
    T100WORD_BITS   order;

    order.BYTE0.BYTE = T100ORDER_XOR;

    info->setValue(order.WORD);
    info->next();

    return T100TRUE;
}
