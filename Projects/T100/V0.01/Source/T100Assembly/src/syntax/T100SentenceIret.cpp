#include "T100SentenceIret.h"

T100SentenceIret::T100SentenceIret(T100SentenceScanner* scanner)
    :T100Sentence(scanner)
{
    //ctor
}

T100SentenceIret::~T100SentenceIret()
{
    //dtor
}

T100BOOL T100SentenceIret::parse()
{
    T100BOOL        result          = T100TRUE;

    setLoaded(T100FALSE);

    if(result){
        type            = T100SENTENCE_IRET;
        m_token->type   = T100SENTENCE_IRET;
    }

    return result;
}

T100BOOL T100SentenceIret::build(T100BuildInfo* info)
{
    T100WORD_BITS   order;

    order.BYTE0.BYTE = T100ORDER_IRET;

    info->setValue(order.WORD);
    info->next();

    return T100TRUE;
}
