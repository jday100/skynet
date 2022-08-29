#include "T100SentenceHalt.h"

T100SentenceHalt::T100SentenceHalt(T100SentenceScanner* scanner)
    :T100Sentence(scanner)
{
    //ctor
}

T100SentenceHalt::~T100SentenceHalt()
{
    //dtor
}

T100BOOL T100SentenceHalt::parse()
{
    T100BOOL        result          = T100TRUE;

    setLoaded(T100FALSE);

    if(result){
        type            = T100SENTENCE_HALT;
        m_token->type   = T100SENTENCE_HALT;
    }

    return result;
}

T100BOOL T100SentenceHalt::build(T100BuildInfo* info)
{
    T100WORD_BITS   order;

    order.BYTE0.BYTE = T100ORDER_HALT;

    info->setValue(order.WORD);
    info->next();

    return T100TRUE;
}
