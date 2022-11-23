#include "T100SentencePop.h"

namespace T100Assembly{

T100SentencePop::T100SentencePop(T100SentenceScanner* scanner)
    :T100SentenceBase(scanner)
{
    //ctor
}

T100SentencePop::~T100SentencePop()
{
    //dtor
}

T100VOID T100SentencePop::init()
{
    T100ProduceInfo::m_token_names[T100SENTENCE_POP] = L"T100SentencePop";
}

T100BOOL T100SentencePop::parse()
{
    T100BOOL        result          = T100TRUE;

    setLoaded(T100FALSE);
    //result = parseOperator(target);

    if(result){
        type            = T100SENTENCE_PUSH;
        m_token->type   = T100SENTENCE_PUSH;
    }

    return result;
}

T100BOOL T100SentencePop::build(T100BuildInfo* info)
{
    return T100FALSE;
}

}
