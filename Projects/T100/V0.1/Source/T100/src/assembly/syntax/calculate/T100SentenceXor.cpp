#include "T100SentenceXor.h"

#include "T100BitTypes.h"

namespace T100Assembly{

T100SentenceXor::T100SentenceXor(T100SentenceScanner* scanner)
    :T100Sentence(scanner)
{
    //ctor
}

T100SentenceXor::~T100SentenceXor()
{
    //dtor
}

T100VOID T100SentenceXor::init()
{
    T100ProduceInfo::m_token_names[T100SENTENCE_XOR] = L"T100SentenceXor";
}

T100BOOL T100SentenceXor::parse()
{
    T100BOOL        result          = T100TRUE;

    setLoaded(T100FALSE);

    if(result){
        type            = T100SENTENCE_XOR;
        m_token->type   = T100SENTENCE_XOR;
    }

    return result;
}

T100BOOL T100SentenceXor::build(T100BuildInfo* info)
{
    T100WORD_BITS       order;

    order.BYTE0.BYTE = T100Component::T100ORDER_XOR;

    info->setValue(order.WORD);
    info->next();

    return T100TRUE;
}

}
