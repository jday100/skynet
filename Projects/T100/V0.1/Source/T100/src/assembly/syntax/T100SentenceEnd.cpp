#include "T100SentenceEnd.h"

namespace T100Assembly{

T100SentenceEnd::T100SentenceEnd(T100SentenceScanner* scanner)
    :T100Sentence(scanner)
{
    //ctor
}

T100SentenceEnd::~T100SentenceEnd()
{
    //dtor
}

T100VOID T100SentenceEnd::init()
{
    T100ProduceInfo::m_token_names[T100SENTENCE_END] = L"T100SentenceEnd";
}

T100BOOL T100SentenceEnd::parse()
{
    T100BOOL        result          = T100TRUE;

    setLoaded(T100FALSE);

    if(result){
        type            = T100SENTENCE_END;
        m_token->type   = T100SENTENCE_END;
    }

    return result;
}

T100BOOL T100SentenceEnd::build(T100BuildInfo* info)
{
    return info->closeSegment();
}

}
