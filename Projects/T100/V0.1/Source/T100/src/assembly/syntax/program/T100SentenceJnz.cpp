#include "T100SentenceJnz.h"

#include "T100BitTypes.h"

namespace T100Assembly{

T100SentenceJnz::T100SentenceJnz(T100SentenceScanner* scanner)
    :T100Sentence(scanner)
{
    //ctor
}

T100SentenceJnz::~T100SentenceJnz()
{
    //dtor
}

T100VOID T100SentenceJnz::init()
{
    T100ProduceInfo::m_token_names[T100SENTENCE_JNZ] = L"T100SentenceJnz";
}

T100BOOL T100SentenceJnz::parse()
{
    T100BOOL        result          = T100TRUE;

    setLoaded(T100FALSE);
    result = parseOperator(target);

    if(result){
        type            = T100SENTENCE_JNZ;
        m_token->type   = T100SENTENCE_JNZ;
    }

    return result;
}

T100BOOL T100SentenceJnz::build(T100BuildInfo* info)
{
    T100BOOL                result;
    T100WORD_BITS           order;
    T100Component::T100OPERATOR_BUILD      build;

    order.BYTE0.BYTE = T100Component::T100ORDER_JNZ;

    result = buildOperator(info, target, build);
    if(!result){
        return T100FALSE;
    }

    info->setValue(order.WORD);
    info->next();

    info->setValue(build.OPERATOR_OFFSET);
    info->next();

    return T100TRUE;
}

}
