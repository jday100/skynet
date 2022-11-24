#include "T100LabelParser.h"

#include "T100AssemblyCommon.h"
#include "T100SentenceBase.h"

namespace T100SentenceBase{

T100LabelParser::T100LabelParser(T100SentenceBase* base)
    :T100ParserBase(base)
{
    //ctor
}

T100LabelParser::~T100LabelParser()
{
    //dtor
}

T100BOOL T100LabelParser::parse(T100OPERATOR& op)
{
    T100BOOL        result          = T100FALSE;

    switch(getParent()->m_type){
    case P_NONE:
        {
            op.NAME         = getParent()->m_item->value;
            op.DATA_TYPE    = T100DATA_LABEL;
            op.PREFIX_TYPE  = P_NONE;

            getParent()->setLoaded(T100FALSE);
            result = T100TRUE;
        }
        break;
    case P_ADDRESS:
        {
            op.NAME         = getParent()->m_item->value;
            op.DATA_TYPE    = T100DATA_LABEL;
            op.PREFIX_TYPE  = P_ADDRESS;

            getParent()->setLoaded(T100FALSE);
            result = T100TRUE;
        }
        break;
    default:
        getParent()->m_token->type  = T100Component::T100TOKEN_ERROR;
        getParent()->m_token->err   = T100Assembly::T100ERROR_SENTENCE;
        //
        result = T100FALSE;
    }

    return result;
}

}
