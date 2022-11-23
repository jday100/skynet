#include "T100SentenceDebug.h"

#include "T100BitTypes.h"

namespace T100Assembly{

T100SentenceDebug::T100SentenceDebug(T100SentenceScanner* scanner)
    :T100Sentence(scanner)
{
    //ctor
}

T100SentenceDebug::~T100SentenceDebug()
{
    //dtor
}

T100VOID T100SentenceDebug::init()
{
    T100ProduceInfo::m_token_names[T100SENTENCE_DEBUG] = L"T100SentenceDebug";
}

T100BOOL T100SentenceDebug::parse()
{
    T100BOOL        result          = T100TRUE;

    setLoaded(T100FALSE);

    if(result){
        type            = T100SENTENCE_DEBUG;
        m_token->type   = T100SENTENCE_DEBUG;
    }

    return result;
}

T100BOOL T100SentenceDebug::build(T100BuildInfo* info)
{
    T100WORD_BITS       order;

    order.BYTE0.BYTE = T100Component::T100ORDER_DBG;

    info->setValue(order.WORD);
    info->next();

    return T100TRUE;
}

}
