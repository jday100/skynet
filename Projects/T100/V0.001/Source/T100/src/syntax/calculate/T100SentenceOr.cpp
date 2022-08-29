#include "T100SentenceOr.h"

#include "T100FileData.h"
#include "T100SentenceScan.h"


T100SentenceOr::T100SentenceOr(T100SentenceScan* scan)
    :T100Sentence(scan)
{
    //ctor
}

T100SentenceOr::~T100SentenceOr()
{
    //dtor
}

T100BOOL T100SentenceOr::parse()
{
    T100BOOL    result      = T100TRUE;

    setLoaded(T100FALSE);

    if(result){
        type            = T100SENTENCE_OR;
        m_token->type   = T100SENTENCE_OR;
    }

    return result;
}

T100BOOL T100SentenceOr::build(T100FileData* code)
{
    T100WORD_BITS order;

    order.BYTE0.BYTE = T100ORDER_OR;

    code->setValue(order.WORD);
    code->next();

    return T100TRUE;
}
