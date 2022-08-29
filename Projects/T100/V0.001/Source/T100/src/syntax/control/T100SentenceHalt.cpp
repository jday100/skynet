#include "T100SentenceHalt.h"

#include "T100FileData.h"
#include "T100SentenceScan.h"


T100SentenceHalt::T100SentenceHalt(T100SentenceScan* scan)
    :T100Sentence(scan)
{
    //ctor
}

T100SentenceHalt::~T100SentenceHalt()
{
    //dtor
}

T100BOOL T100SentenceHalt::parse()
{
    T100BOOL    result      = T100TRUE;

    setLoaded(T100FALSE);

    if(result){
        type            = T100SENTENCE_HALT;
        m_token->type   = T100SENTENCE_HALT;
    }

    return result;
}

T100BOOL T100SentenceHalt::build(T100FileData* code)
{
    T100WORD_BITS order;

    order.BYTE0.BYTE = T100ORDER_HALT;

    code->setValue(order.WORD);
    code->next();

    return T100TRUE;
}
