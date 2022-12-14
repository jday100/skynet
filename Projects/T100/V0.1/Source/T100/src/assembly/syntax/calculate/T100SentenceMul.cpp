#include "T100SentenceMul.h"

#include "T100BitTypes.h"

namespace T100Assembly{

T100SentenceMul::T100SentenceMul(T100SentenceScanner* scanner)
    :T100Sentence(scanner)
{
    //ctor
}

T100SentenceMul::~T100SentenceMul()
{
    //dtor
}

T100VOID T100SentenceMul::init()
{
    T100ProduceInfo::m_token_names[T100SENTENCE_MUL] = L"T100SentenceMul";
}

T100BOOL T100SentenceMul::parse()
{
    T100BOOL        result          = T100TRUE;

    setLoaded(T100FALSE);

    if(result){
        type            = T100SENTENCE_MUL;
        m_token->type   = T100SENTENCE_MUL;
    }

    return result;
}

T100BOOL T100SentenceMul::build(T100BuildInfo* info)
{
    T100WORD_BITS       order;

    order.BYTE0.BYTE    = T100Component::T100ORDER_MUL;

    info->setValue(order.WORD);
    info->next();

    return T100TRUE;
}

}
