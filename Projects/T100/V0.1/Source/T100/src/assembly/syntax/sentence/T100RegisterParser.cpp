#include "T100RegisterParser.h"

#include "T100SentenceBase.h"

namespace T100SentenceBase{

T100RegisterParser::T100RegisterParser(T100SentenceBase* base)
    :T100ParserBase(base)
{
    //ctor
}

T100RegisterParser::~T100RegisterParser()
{
    //dtor
}

T100BOOL T100RegisterParser::parse(T100OPERATOR& op)
{
    switch(getParent()->m_item->type){
    case T100Assembly::T100KEYWORD_COR:
        {
            op.DATA_TYPE    = T100DATA_COR;
            op.PREFIX_TYPE  = getParent()->m_type;
            getParent()->setLoaded(T100FALSE);
        }
        break;
    case T100Assembly::T100KEYWORD_CBR:
        {
            op.DATA_TYPE    = T100DATA_CBR;
            op.PREFIX_TYPE  = getParent()->m_type;
            getParent()->setLoaded(T100FALSE);
        }
        break;
    case T100Assembly::T100KEYWORD_CCR:
        {
            op.DATA_TYPE    = T100DATA_CCR;
            op.PREFIX_TYPE  = getParent()->m_type;
            getParent()->setLoaded(T100FALSE);
        }
        break;
    case T100Assembly::T100KEYWORD_SSR:
        {
            op.DATA_TYPE    = T100DATA_SSR;
            op.PREFIX_TYPE  = getParent()->m_type;
            getParent()->setLoaded(T100FALSE);
        }
        break;
    case T100Assembly::T100KEYWORD_SPR:
        {
            op.DATA_TYPE    = T100DATA_SPR;
            op.PREFIX_TYPE  = getParent()->m_type;
            getParent()->setLoaded(T100FALSE);
        }
        break;
    case T100Assembly::T100KEYWORD_AAR:
        {
            op.DATA_TYPE    = T100DATA_AAR;
            op.PREFIX_TYPE  = getParent()->m_type;
            getParent()->setLoaded(T100FALSE);
        }
        break;
    case T100Assembly::T100KEYWORD_ABR:
        {
            op.DATA_TYPE    = T100DATA_ABR;
            op.PREFIX_TYPE  = getParent()->m_type;
            getParent()->setLoaded(T100FALSE);
        }
        break;
    case T100Assembly::T100KEYWORD_ACR:
        {
            op.DATA_TYPE    = T100DATA_ACR;
            op.PREFIX_TYPE  = getParent()->m_type;
            getParent()->setLoaded(T100FALSE);
        }
        break;
    case T100Assembly::T100KEYWORD_ADR:
        {
            op.DATA_TYPE    = T100DATA_ADR;
            op.PREFIX_TYPE  = getParent()->m_type;
            getParent()->setLoaded(T100FALSE);
        }
        break;
    case T100Assembly::T100KEYWORD_ACF:
        {
            op.DATA_TYPE    = T100DATA_ACF;
            op.PREFIX_TYPE  = getParent()->m_type;
            getParent()->setLoaded(T100FALSE);
        }
        break;
    case T100Assembly::T100KEYWORD_AMF:
        {
            op.DATA_TYPE    = T100DATA_AMF;
            op.PREFIX_TYPE  = getParent()->m_type;
            getParent()->setLoaded(T100FALSE);
        }
        break;
    case T100Assembly::T100KEYWORD_AOF:
        {
            op.DATA_TYPE    = T100DATA_AOF;
            op.PREFIX_TYPE  = getParent()->m_type;
            getParent()->setLoaded(T100FALSE);
        }
        break;
    default:
        return T100FALSE;
    }

    return T100TRUE;
}

T100BOOL T100RegisterParser::parseAll(T100OPERATOR& op)
{
    switch(getParent()->m_item->type){
    case T100Assembly::T100KEYWORD_ALL:
        {
            op.DATA_TYPE    = T100DATA_ALL;
            op.PREFIX_TYPE  = getParent()->m_type;
            getParent()->setLoaded(T100FALSE);
        }
        break;
    default:
        return parse(op);
    }

    return T100TRUE;
}

}
