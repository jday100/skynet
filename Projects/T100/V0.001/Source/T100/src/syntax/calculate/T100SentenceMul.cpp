#include "T100SentenceMul.h"

#include "T100FileData.h"
#include "T100SentenceScan.h"


T100SentenceMul::T100SentenceMul(T100SentenceScan* scan)
    :T100Sentence(scan)
{
    //ctor
}

T100SentenceMul::~T100SentenceMul()
{
    //dtor
}

T100BOOL T100SentenceMul::parse()
{
    T100BOOL    result      = T100TRUE;

    setLoaded(T100FALSE);

    if(result){
        type            = T100SENTENCE_MUL;
        m_token->type   = T100SENTENCE_MUL;
    }

    return result;
}

T100BOOL T100SentenceMul::build(T100FileData* code)
{
    T100WORD_BITS order;

    order.BYTE0.BYTE = T100ORDER_MUL;

    code->setValue(order.WORD);
    code->next();

    return T100TRUE;
}
