#include "T100SentenceNot.h"

#include "T100FileData.h"
#include "T100SentenceScan.h"


T100SentenceNot::T100SentenceNot(T100SentenceScan* scan)
    :T100Sentence(scan)
{
    //ctor
}

T100SentenceNot::~T100SentenceNot()
{
    //dtor
}

T100BOOL T100SentenceNot::parse()
{
    T100BOOL    result      = T100TRUE;

    setLoaded(T100FALSE);

    if(result){
        type            = T100SENTENCE_NOT;
        m_token->type   = T100SENTENCE_NOT;
    }

    return result;
}

T100BOOL T100SentenceNot::build(T100FileData* code)
{
    T100WORD_BITS order;

    order.BYTE0.BYTE = T100ORDER_NOT;

    code->setValue(order.WORD);
    code->next();

    return T100TRUE;
}
