#include "T100SentenceAnd.h"

#include "T100FileData.h"
#include "T100SentenceScan.h"


T100SentenceAnd::T100SentenceAnd(T100SentenceScan* scan)
    :T100Sentence(scan)
{
    //ctor
}

T100SentenceAnd::~T100SentenceAnd()
{
    //dtor
}

T100BOOL T100SentenceAnd::parse()
{
    T100BOOL    result      = T100TRUE;

    setLoaded(T100FALSE);

    if(result){
        type            = T100SENTENCE_AND;
        m_token->type   = T100SENTENCE_AND;
    }

    return result;
}

T100BOOL T100SentenceAnd::build(T100FileData* code)
{
    T100WORD_BITS order;

    order.BYTE0.BYTE = T100ORDER_AND;

    code->setValue(order.WORD);
    code->next();

    return T100TRUE;
}
