#include "T100SentenceSub.h"

#include "T100BitTypes.h"

namespace T100Assembly{

T100SentenceSub::T100SentenceSub(T100SentenceScanner* scanner)
    :T100Sentence(scanner)
{
    //ctor
}

T100SentenceSub::~T100SentenceSub()
{
    //dtor
}

T100VOID T100SentenceSub::init()
{
    T100ProduceInfo::m_token_names[T100SENTENCE_SUB] = L"T100SentenceSub";
}

T100BOOL T100SentenceSub::parse()
{
    T100BOOL        result          = T100TRUE;

    setLoaded(T100FALSE);

    if(result){
        type            = T100SENTENCE_SUB;
        m_token->type   = T100SENTENCE_SUB;
    }

    return result;
}

T100BOOL T100SentenceSub::build(T100BuildInfo* info)
{
    T100WORD_BITS       order;

    order.BYTE0.BYTE = T100Component::T100ORDER_SUB;

    info->setValue(order.WORD);
    info->next();

    return T100TRUE;
}

}
