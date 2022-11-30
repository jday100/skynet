#include "T100SentenceEnter.h"

#include "T100BitTypes.h"

namespace T100Assembly{

T100SentenceEnter::T100SentenceEnter(T100SentenceScanner* scanner)
    :T100SentenceBase(scanner)
{
    //ctor
}

T100SentenceEnter::~T100SentenceEnter()
{
    //dtor
}

T100VOID T100SentenceEnter::init()
{
    T100ProduceInfo::m_token_names[T100SENTENCE_ENTER] = L"T100SentenceEnter";
}

T100BOOL T100SentenceEnter::parse()
{
    T100BOOL        result          = T100TRUE;

    setLoaded(T100FALSE);

    if(result){
        type            = T100SENTENCE_ENTER;
        m_token->type   = T100SENTENCE_ENTER;
    }

    return result;
}

T100BOOL T100SentenceEnter::build(T100BuildInfo* info)
{
    T100WORD_BITS       order;

    order.BYTE0.BYTE    = T100Component::T100ORDER_ENTER;

    info->setValue(order.WORD);
    info->next();

    return T100TRUE;
}


}
