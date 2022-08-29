#include "T100SentenceDiv.h"

#include "T100FileData.h"
#include "T100SentenceScan.h"


T100SentenceDiv::T100SentenceDiv(T100SentenceScan* scan)
    :T100Sentence(scan)
{
    //ctor
}

T100SentenceDiv::~T100SentenceDiv()
{
    //dtor
}

T100BOOL T100SentenceDiv::parse()
{
    T100BOOL    result      = T100TRUE;

    setLoaded(T100FALSE);

    if(result){
        type            = T100SENTENCE_DIV;
        m_token->type   = T100SENTENCE_DIV;
    }

    return result;
}

T100BOOL T100SentenceDiv::build(T100FileData* code)
{
    T100WORD_BITS order;

    order.BYTE0.BYTE = T100ORDER_DIV;

    code->setValue(order.WORD);
    code->next();

    return T100TRUE;
}
