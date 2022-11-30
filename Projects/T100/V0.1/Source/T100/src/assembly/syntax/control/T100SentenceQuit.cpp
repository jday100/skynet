#include "T100SentenceQuit.h"

#include "T100BitTypes.h"

namespace T100Assembly{

T100SentenceQuit::T100SentenceQuit(T100SentenceScanner* scanner)
    :T100SentenceBase(scanner)
{
    //ctor
}

T100SentenceQuit::~T100SentenceQuit()
{
    //dtor
}

T100VOID T100SentenceQuit::init()
{
    T100ProduceInfo::m_token_names[T100SENTENCE_QUIT] = L"T100SentenceQuit";
}

T100BOOL T100SentenceQuit::parse()
{
    T100BOOL        result          = T100TRUE;

    setLoaded(T100FALSE);

    if(result){
        type            = T100SENTENCE_QUIT;
        m_token->type   = T100SENTENCE_QUIT;
    }

    return result;
}

T100BOOL T100SentenceQuit::build(T100BuildInfo* info)
{
    T100WORD_BITS       order;

    order.BYTE0.BYTE    = T100Component::T100ORDER_QUIT;

    info->setValue(order.WORD);
    info->next();

    return T100TRUE;
}

}
