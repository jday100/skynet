#include "T100SentenceIret.h"

#include "T100FileData.h"
#include "T100SentenceScan.h"


T100SentenceIret::T100SentenceIret(T100SentenceScan* scan)
    :T100Sentence(scan)
{
    //ctor
}

T100SentenceIret::~T100SentenceIret()
{
    //dtor
}

T100BOOL T100SentenceIret::parse()
{
    T100BOOL    result      = T100TRUE;

    setLoaded(T100FALSE);

    if(result){
        type            = T100SENTENCE_IRET;
        m_token->type   = T100SENTENCE_IRET;
    }

    return result;
}

T100BOOL T100SentenceIret::build(T100FileData* code)
{
    T100WORD_BITS order;

    order.BYTE0.BYTE = T100ORDER_IRET;

    code->setValue(order.WORD);
    code->next();

    return T100TRUE;
}
