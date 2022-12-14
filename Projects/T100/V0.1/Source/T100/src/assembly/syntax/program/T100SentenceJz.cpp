#include "T100SentenceJz.h"

#include "T100BitTypes.h"

namespace T100Assembly{

T100SentenceJz::T100SentenceJz(T100SentenceScanner* scanner)
    :T100Sentence(scanner)
{
    //ctor
}

T100SentenceJz::~T100SentenceJz()
{
    //dtor
}

T100VOID T100SentenceJz::init()
{
    T100ProduceInfo::m_token_names[T100SENTENCE_JZ] = L"T100SentenceJz";
}

T100BOOL T100SentenceJz::parse()
{
    T100BOOL        result          = T100TRUE;

    setLoaded(T100FALSE);
    result = parseOperator(target);

    if(result){
        type            = T100SENTENCE_JZ;
        m_token->type   = T100SENTENCE_JZ;
    }

    return result;
}

T100BOOL T100SentenceJz::build(T100BuildInfo* info)
{
    T100BOOL                result;
    T100WORD_BITS           order;
    T100Component::T100OPERATOR_BUILD      build;

    order.BYTE0.BYTE    = T100Component::T100ORDER_JZ;

    build.BASE_USED     = T100FALSE;
    build.BASE_TYPE     = T100Component::T_NONE;
    result = buildOperator(info, target, build);
    if(!result){
        return T100FALSE;
    }

    info->setValue(order.WORD);
    info->next();

    info->setValue(build.OPERATOR_VALUE);
    info->next();

    return T100TRUE;
}

}
