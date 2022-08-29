#include "T100SentenceEnd.h"

#include "T100FileData.h"
#include "T100SentenceScan.h"


T100SentenceEnd::T100SentenceEnd(T100SentenceScan* scan)
    :T100Sentence(scan)
{
    //ctor
}

T100SentenceEnd::~T100SentenceEnd()
{
    //dtor
}

T100BOOL T100SentenceEnd::parse()
{
    T100BOOL    result      = T100TRUE;

    setLoaded(T100FALSE);

    if(result){
        type            = T100SENTENCE_END;
        m_token->type   = T100SENTENCE_END;
    }

    return result;
}

T100BOOL T100SentenceEnd::build(T100FileData* code)
{
    return code->addSegment();
}
