#include "T100SentenceIn.h"

T100SentenceIn::T100SentenceIn(T100SentenceScanner* scanner)
    :T100Sentence(scanner)
{
    //ctor
}

T100SentenceIn::~T100SentenceIn()
{
    //dtor
}

T100BOOL T100SentenceIn::parse()
{
    T100BOOL        result          = T100TRUE;

    setLoaded(T100FALSE);
    result = parseComplexus(target);
    if(!result){
        return T100FALSE;
    }

    result = parseOperator(source);

    if(result){
        type            = T100SENTENCE_IN;
        m_token->type   = T100SENTENCE_IN;
    }

    return result;
}

T100BOOL T100SentenceIn::build(T100BuildInfo* info)
{
    T100BOOL            result      = T100FALSE;
    T100WORD_BITS       order;
    T100OPERATOR_INFO   build;

    switch(target.TYPE){
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

    result = buildOperator(info, target, build.TARGET);
    if(!result){
        //T100Error::error(T100AssemblyHint::build_hint(type, data, T100BUILD_SENTENCE_ERROR));
        return T100FALSE;
    };

    build.SOURCE.OFFSET      = build.TARGET.OFFSET;
    build.SOURCE.BASE_USED   = T100FALSE;
    build.SOURCE.BASE_TYPE   = T_NONE;
    result = buildOperator(info, source, build.SOURCE);
    if(!result){
        //T100Error::error(T100AssemblyHint::build_hint(type, data, T100BUILD_SENTENCE_ERROR));
        return T100FALSE;
    };

    build.TYPE           = target.TYPE;

    result = buildInfo(T100ORDER_IN, info, build);
    if(!result){
        //T100Error::error(T100AssemblyHint::build_hint(type, data, T100BUILD_SENTENCE_ERROR));
        return T100FALSE;
    }

    return result;
}
