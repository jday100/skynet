#include "T100SentenceAdd.h"

#include "T100BuildInfo.h"


T100SentenceAdd::T100SentenceAdd(T100SentenceScanner* scanner)
    :T100Sentence(scanner)
{
    //ctor
}

T100SentenceAdd::~T100SentenceAdd()
{
    //dtor
}

T100BOOL T100SentenceAdd::parse()
{
    T100BOOL        result          = T100TRUE;

    setLoaded(T100FALSE);

    if(result){
        type            = T100SENTENCE_ADD;
        m_token->type   = T100SENTENCE_ADD;
    }

    return result;
}

T100BOOL T100SentenceAdd::build(T100BuildInfo* info)
{
    T100WORD_BITS   order;

    order.BYTE0.BYTE = T100ORDER_ADD;

    info->setValue(order.WORD);
    info->next();

    return T100TRUE;
}
