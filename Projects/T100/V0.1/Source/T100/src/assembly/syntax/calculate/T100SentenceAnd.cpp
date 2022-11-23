#include "T100SentenceAnd.h"

#include "T100BitTypes.h"

namespace T100Assembly{

T100SentenceAnd::T100SentenceAnd(T100SentenceScanner* scanner)
    :T100Sentence(scanner)
{
    //ctor
}

T100SentenceAnd::~T100SentenceAnd()
{
    //dtor
}

T100VOID T100SentenceAnd::init()
{
    T100ProduceInfo::m_token_names[T100SENTENCE_AND] = L"T100SentenceAnd";
}

T100BOOL T100SentenceAnd::parse()
{
    T100BOOL        result          = T100TRUE;

    setLoaded(T100FALSE);

    if(result){
        type            = T100SENTENCE_AND;
        m_token->type   = T100SENTENCE_AND;
    }

    return result;
}

T100BOOL T100SentenceAnd::build(T100BuildInfo* info)
{
    T100WORD_BITS       order;

    order.BYTE0.BYTE = T100Component::T100ORDER_AND;

    info->setValue(order.WORD);
    info->next();

    return T100TRUE;
}

}
