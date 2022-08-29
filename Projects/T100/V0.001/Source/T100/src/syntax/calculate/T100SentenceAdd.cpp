#include "T100SentenceAdd.h"

#include "T100FileData.h"
#include "T100SentenceScan.h"


T100SentenceAdd::T100SentenceAdd(T100SentenceScan* scan)
    :T100Sentence(scan)
{
    //ctor
}

T100SentenceAdd::~T100SentenceAdd()
{
    //dtor
}

T100BOOL T100SentenceAdd::parse()
{
    T100BOOL    result      = T100TRUE;

    setLoaded(T100FALSE);

    if(result){
        type            = T100SENTENCE_ADD;
        m_token->type   = T100SENTENCE_ADD;
    }

    return result;
}

T100BOOL T100SentenceAdd::build(T100FileData* code)
{
    T100WORD_BITS order;

    order.BYTE0.BYTE = T100ORDER_ADD;

    code->setValue(order.WORD);
    code->next();

    return T100TRUE;
}
