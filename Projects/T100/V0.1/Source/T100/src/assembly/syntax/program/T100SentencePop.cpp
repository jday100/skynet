#include "T100SentencePop.h"

#include "T100BitTypes.h"
#include "T100SentenceCommon.h"

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
    result = getOperatorParser().parseAll(target);

    if(result){
        type            = T100SENTENCE_POP;
        m_token->type   = T100SENTENCE_POP;
    }

    return result;
}

T100BOOL T100SentencePop::build(T100BuildInfo* info)
{
    T100BOOL            result;
    T100WORD_BITS       order;
    ::T100SentenceBase::T100OPERATOR_BUILD      build;

    order.BYTE0.BYTE    = T100Component::T100ORDER_POP;

    result = getOperatorBuilder().buildAll(info, target, build);
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
