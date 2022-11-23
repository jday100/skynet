#include "T100SentencePush.h"

namespace T100Assembly{

T100SentencePush::T100SentencePush(T100SentenceScanner* scanner)
    :T100SentenceBase(scanner)
{
    //ctor
}

T100SentencePush::~T100SentencePush()
{
    //dtor
}

T100VOID T100SentencePush::init()
{
    T100ProduceInfo::m_token_names[T100SENTENCE_PUSH] = L"T100SentencePush";
}

T100BOOL T100SentencePush::parse()
{
    T100BOOL        result          = T100TRUE;

    setLoaded(T100FALSE);
    result = getOperatorParser().parse(target);

    if(result){
        type            = T100SENTENCE_PUSH;
        m_token->type   = T100SENTENCE_PUSH;
    }

    return result;
}

T100BOOL T100SentencePush::build(T100BuildInfo* info)
{
    return T100FALSE;
}

}
