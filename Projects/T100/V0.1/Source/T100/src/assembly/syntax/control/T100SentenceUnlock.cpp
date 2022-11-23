#include "T100SentenceUnlock.h"

#include "T100BitTypes.h"

namespace T100Assembly{

T100SentenceUnlock::T100SentenceUnlock(T100SentenceScanner* scanner)
    :T100Sentence(scanner)
{
    //ctor
}

T100SentenceUnlock::~T100SentenceUnlock()
{
    //dtor
}

T100VOID T100SentenceUnlock::init()
{
    T100ProduceInfo::m_token_names[T100SENTENCE_UNLOCK] = L"T100SentenceUnlock";
}

T100BOOL T100SentenceUnlock::parse()
{
    T100BOOL        result          = T100TRUE;

    setLoaded(T100FALSE);

    if(result){
        type            = T100SENTENCE_UNLOCK;
        m_token->type   = T100SENTENCE_UNLOCK;
    }

    return result;
}

T100BOOL T100SentenceUnlock::build(T100BuildInfo* info)
{
    T100WORD_BITS       order;

    order.BYTE0.BYTE = T100Component::T100ORDER_UNLOCK;

    info->setValue(order.WORD);
    info->next();

    return T100TRUE;
}

}
