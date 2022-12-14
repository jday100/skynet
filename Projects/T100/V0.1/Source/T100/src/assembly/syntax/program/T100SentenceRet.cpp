#include "T100SentenceRet.h"

#include "T100BitTypes.h"

namespace T100Assembly{

T100SentenceRet::T100SentenceRet(T100SentenceScanner* scanner)
    :T100Sentence(scanner)
{
    //ctor
}

T100SentenceRet::~T100SentenceRet()
{
    //dtor
}

T100VOID T100SentenceRet::init()
{
    T100ProduceInfo::m_token_names[T100SENTENCE_RETURN] = L"T100SentenceRet";
}

T100BOOL T100SentenceRet::parse()
{
    T100BOOL        result          = T100TRUE;

    setLoaded(T100FALSE);

    if(result){
        type            = T100SENTENCE_RETURN;
        m_token->type   = T100SENTENCE_RETURN;
    }

    return result;
}

T100BOOL T100SentenceRet::build(T100BuildInfo* info)
{
    T100WORD_BITS       order;

    order.BYTE0.BYTE = T100Component::T100ORDER_RETURN;

    info->setValue(order.WORD);
    info->next();

    return T100TRUE;
}

}
