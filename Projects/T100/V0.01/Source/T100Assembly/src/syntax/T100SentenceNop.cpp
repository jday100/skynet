#include "T100SentenceNop.h"

T100SentenceNop::T100SentenceNop(T100SentenceScanner* scanner)
    :T100Sentence(scanner)
{
    //ctor
}

T100SentenceNop::~T100SentenceNop()
{
    //dtor
}

T100BOOL T100SentenceNop::parse()
{
    T100BOOL        result          = T100TRUE;

    setLoaded(T100FALSE);

    if(result){
        type            = T100SENTENCE_NOP;
        m_token->type   = T100SENTENCE_NOP;
    }

    return result;
}

T100BOOL T100SentenceNop::build(T100BuildInfo* info)
{
    T100WORD_BITS   order;

    order.BYTE0.BYTE = T100ORDER_NOP;

    info->setValue(order.WORD);
    info->next();

    return T100TRUE;
}
