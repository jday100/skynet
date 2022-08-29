#include "T100SentenceJz.h"

T100SentenceJz::T100SentenceJz(T100SentenceScanner* scanner)
    :T100Sentence(scanner)
{
    //ctor
}

T100SentenceJz::~T100SentenceJz()
{
    //dtor
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
    T100BOOL            result;
    T100WORD_BITS       order;
    T100OPERATOR_BUILD  build;

    order.BYTE0.BYTE = T100ORDER_JZ;

    build.BASE_USED  = T100FALSE;
    build.BASE_TYPE  = T_NONE;
    result = buildOperator(info, target, build);
    if(!result){
        //T100Error::error(T100AssemblyHint::build_hint(type, data, T100BUILD_SENTENCE_ERROR));
        return T100FALSE;
    }

    info->setValue(order.WORD);
    info->next();

    info->setValue(build.OPERATOR_VALUE);
    info->next();

    return T100TRUE;
}
