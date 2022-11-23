#include "T100SentenceNot.h"

#include "T100BitTypes.h"

namespace T100Assembly{

T100SentenceNot::T100SentenceNot(T100SentenceScanner* scanner)
    :T100Sentence(scanner)
{
    //ctor
}

T100SentenceNot::~T100SentenceNot()
{
    //dtor
}

T100VOID T100SentenceNot::init()
{
    T100ProduceInfo::m_token_names[T100SENTENCE_NOT] = L"T100SentenceNot";
}

T100BOOL T100SentenceNot::parse()
{
    T100BOOL        result          = T100TRUE;

    setLoaded(T100FALSE);

    if(result){
        type            = T100SENTENCE_NOT;
        m_token->type   = T100SENTENCE_NOT;
    }

    return result;
}

T100BOOL T100SentenceNot::build(T100BuildInfo* info)
{
    T100WORD_BITS       order;

    order.BYTE0.BYTE    = T100Component::T100ORDER_NOT;

    info->setValue(order.WORD);
    info->next();

    return T100TRUE;
}

}
