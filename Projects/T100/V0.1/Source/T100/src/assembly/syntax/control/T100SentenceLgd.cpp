#include "T100SentenceLgd.h"

#include "T100BitTypes.h"
#include "T100SentenceCommon.h"

namespace T100Assembly{

T100SentenceLgd::T100SentenceLgd(T100SentenceScanner* scanner)
    :T100SentenceBase(scanner)
{
    //ctor
}

T100SentenceLgd::~T100SentenceLgd()
{
    //dtor
}

T100VOID T100SentenceLgd::init()
{
    T100ProduceInfo::m_token_names[T100SENTENCE_LGD] = L"T100SentenceLgd";
}

T100BOOL T100SentenceLgd::parse()
{
    T100BOOL        result          = T100TRUE;

    setLoaded(T100FALSE);
    result = getComplexusParser().parse(target);

    if(result){
        type            = T100SENTENCE_LGD;
        m_token->type   = T100SENTENCE_LGD;
    }

    return result;
}

T100BOOL T100SentenceLgd::build(T100BuildInfo* info)
{
    T100BOOL            result;

    result = getComplexusBuilder().build(info, target, T100Component::T100ORDER_LGD);

    return result;
}

}
