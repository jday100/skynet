#include "T100SentenceXor.h"

#include "T100FileData.h"
#include "T100SentenceScan.h"


T100SentenceXor::T100SentenceXor(T100SentenceScan* scan)
    :T100Sentence(scan)
{
    //ctor
}

T100SentenceXor::~T100SentenceXor()
{
    //dtor
}

T100BOOL T100SentenceXor::parse()
{
    T100BOOL    result      = T100TRUE;

    setLoaded(T100FALSE);

    if(result){
        type            = T100SENTENCE_XOR;
        m_token->type   = T100SENTENCE_XOR;
    }

    return result;
}

T100BOOL T100SentenceXor::build(T100FileData* code)
{
    T100WORD_BITS order;

    order.BYTE0.BYTE = T100ORDER_XOR;

    code->setValue(order.WORD);
    code->next();

    return T100TRUE;
}
