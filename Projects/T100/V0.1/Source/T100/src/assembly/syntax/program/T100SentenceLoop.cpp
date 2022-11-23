#include "T100SentenceLoop.h"

#include "T100BitTypes.h"

namespace T100Assembly{

T100SentenceLoop::T100SentenceLoop(T100SentenceScanner* scanner)
    :T100Sentence(scanner)
{
    //ctor
}

T100SentenceLoop::~T100SentenceLoop()
{
    //dtor
}

T100VOID T100SentenceLoop::init()
{
    T100ProduceInfo::m_token_names[T100SENTENCE_LOOP] = L"T100SentenceLoop";
}

T100BOOL T100SentenceLoop::parse()
{
    T100BOOL        result          = T100TRUE;

    setLoaded(T100FALSE);
    result = parseOperator(target);

    if(result){
        type            = T100SENTENCE_LOOP;
        m_token->type   = T100SENTENCE_LOOP;
    }

    return result;
}

T100BOOL T100SentenceLoop::build(T100BuildInfo* info)
{
    T100BOOL                result;
    T100WORD_BITS           order;
    T100Component::T100OPERATOR_BUILD      build;

    order.BYTE0.BYTE    = T100Component::T100ORDER_LOOP;

    build.BASE_USED     = T100FALSE;
    build.BASE_TYPE     = T100Component::T_NONE;
    result = buildOperator(info, target, build);
    if(!result){
        return T100FALSE;
    }

    order.BYTE1.BYTE = build.BASE_TYPE;
    order.BYTE2.BYTE = build.OPERATOR_TYPE;

    info->setValue(order.WORD);
    info->next();

    info->setValue(build.OPERATOR_VALUE);
    info->next();

    return T100TRUE;
}

}
