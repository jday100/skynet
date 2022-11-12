#include "T100SentenceJump.h"

namespace T100Assembly{

T100SentenceJump::T100SentenceJump(T100SentenceScanner* scanner)
    :T100Scanner(scanner)
{
    //ctor
}

T100SentenceJump::~T100SentenceJump()
{
    //dtor
}

T100BOOL T100SentenceJump::parse()
{
    T100BOOL        result          = T100TRUE;

    setLoaded(T100FALSE);
    result = parseOperator(target);

    if(result){
        type            = T100SENTENCE_JUMP;
        m_token->type   = T100SENTENCE_JUMP;
    }

    return result;
}

T100BOOL T100SentenceJump::build(T100BuildInfo* info)
{
    T100BOOL                result;
    T100WORD_BITS           order;
    T100OPERATOR_BUILD      build;

    order.BYTE0.BYTE = T100ORDER_JUMP;

    result = buildOperator(info, target, build);
    if(!result){
        return T100FALSE;
    }

    order.BYTE1.BYTE = build.BASE_TYPE;
    order.BYTE2.BYTE = build.OPERATOR_TYPE;

    info->setValue(order.WORD);
    info->next();

    if(build.BASE_USED && build>BASE_FLAG){
        info->setValue(build.BASE_VALUE);
        info->next();
    }

    if(build.OPERATOR_FLAG){
        info->setValue(build.OPERATOR_VALUE);
        info->next();
    }

    return result;
}

}
