#include "T100SentencePush.h"

#include "T100BitTypes.h"
#include "T100SentenceCommon.h"

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
    result = getOperatorParser().parseAll(target);

    if(result){
        type            = T100SENTENCE_PUSH;
        m_token->type   = T100SENTENCE_PUSH;
    }

    return result;
}

T100BOOL T100SentencePush::build(T100BuildInfo* info)
{
    T100BOOL            result;
    T100WORD_BITS       order;
    ::T100SentenceBase::T100OPERATOR_BUILD      build;

    order.BYTE0.BYTE    = T100Component::T100ORDER_PUSH;

    result = getOperatorBuilder().build(info, target, build);
    if(!result){
        return T100FALSE;
    }

    order.BYTE3.BYTE    = build.TYPE;

    info->setValue(order.WORD);
    info->next();

    if(build.FLAG){
        info->setValue(build.VALUE);
        info->next();;
    }

    return result;
}

}
