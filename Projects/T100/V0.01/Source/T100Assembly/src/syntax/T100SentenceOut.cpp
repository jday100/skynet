#include "T100SentenceOut.h"

T100SentenceOut::T100SentenceOut(T100SentenceScanner* scanner)
    :T100Sentence(scanner)
{
    //ctor
}

T100SentenceOut::~T100SentenceOut()
{
    //dtor
}

T100BOOL T100SentenceOut::parse()
{
    T100BOOL        result          = T100TRUE;

    setLoaded(T100FALSE);
    result = parseOperator(target);
    if(!result){
        return T100FALSE;
    }

    result = parseComplexus(source);

    if(result){
        type            = T100SENTENCE_OUT;
        m_token->type   = T100SENTENCE_OUT;
    }

    return result;
}

T100BOOL T100SentenceOut::build(T100BuildInfo* info)
{
    T100BOOL                result      = T100FALSE;
    T100OPERATOR_INFO       build;

    switch(source.TYPE){
    case T100OPERATOR_ONE_ONE:
        {
            build.TARGET.OFFSET  = 0;
        }
        break;
    case T100OPERATOR_THREE_THREE:
        {
            build.TARGET.OFFSET  = 1;
        }
        break;
    default:
        build.TARGET.OFFSET = 0;
    }

    build.TARGET.BASE_USED   = T100FALSE;
    build.TARGET.BASE_TYPE   = T_NONE;
    result = buildOperator(info, target, build.TARGET);
    if(!result){
        //T100Error::error(T100AssemblyHint::build_hint(type, data, T100BUILD_SENTENCE_ERROR));
        return T100FALSE;
    }

    build.SOURCE.OFFSET  = build.TARGET.OFFSET;
    result = buildComplexus(info, source, build.SOURCE);
    if(!result){
        //T100Error::error(T100AssemblyHint::build_hint(type, data, T100BUILD_SENTENCE_ERROR));
        return T100FALSE;
    }

    build.TYPE           = source.TYPE;

    result = buildInfo(T100ORDER_OUT, info, build);
    if(!result){
        //T100Error::error(T100AssemblyHint::build_hint(type, data, T100BUILD_SENTENCE_ERROR));
        return T100FALSE;
    }

    return result;
}
