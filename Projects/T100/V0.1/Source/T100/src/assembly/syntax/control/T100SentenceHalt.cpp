#include "T100SentenceHalt.h"

#include "T100BitTypes.h"

namespace T100Assembly{

T100SentenceHalt::T100SentenceHalt(T100SentenceScanner* scanner)
    :T100Sentence(scanner)
{
    //ctor
}

T100SentenceHalt::~T100SentenceHalt()
{
    //dtor
}

T100VOID T100SentenceHalt::init()
{
    T100ProduceInfo::m_token_names[T100SENTENCE_HALT] = L"T100SentenceHalt";
}

T100BOOL T100SentenceHalt::parse()
{
    T100BOOL        result          = T100TRUE;

    setLoaded(T100FALSE);

    if(result){
        type            = T100SENTENCE_HALT;
        m_token->type   = T100SENTENCE_HALT;
    }

    return result;
}

T100BOOL T100SentenceHalt::build(T100BuildInfo* info)
{
    T100WORD_BITS       order;

    order.BYTE0.BYTE = T100Component::T100ORDER_HALT;

    info->setValue(order.WORD);
    info->next();

    return T100TRUE;
}

}
