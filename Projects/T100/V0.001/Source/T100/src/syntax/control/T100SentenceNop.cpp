#include "T100SentenceNop.h"

#include "T100FileData.h"
#include "T100SentenceScan.h"


T100SentenceNop::T100SentenceNop(T100SentenceScan* scan)
    :T100Sentence(scan)
{
    //ctor
}

T100SentenceNop::~T100SentenceNop()
{
    //dtor
}

T100BOOL T100SentenceNop::parse()
{
    T100BOOL    result      = T100TRUE;

    setLoaded(T100FALSE);

    if(result){
        type            = T100SENTENCE_NOP;
        m_token->type   = T100SENTENCE_NOP;
    }

    return result;
}

T100BOOL T100SentenceNop::build(T100FileData* code)
{
    T100WORD_BITS order;

    order.BYTE0.BYTE = T100ORDER_NOP;

    code->setValue(order.WORD);
    code->next();

    return T100TRUE;
}
