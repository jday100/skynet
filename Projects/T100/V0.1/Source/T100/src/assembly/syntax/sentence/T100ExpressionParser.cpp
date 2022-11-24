#include "T100ExpressionParser.h"

#include "T100AssemblyCommon.h"
#include "T100SentenceBase.h"

namespace T100SentenceBase{

T100ExpressionParser::T100ExpressionParser(T100SentenceBase* base)
    :T100ParserBase(base)
{
    //ctor
}

T100ExpressionParser::~T100ExpressionParser()
{
    //dtor
}

T100BOOL T100ExpressionParser::parse(T100OPERATOR& op)
{
    T100BOOL        result          = T100FALSE;

    getParent()->setLoaded(T100TRUE);

READ_NEXT:
    if(!getParent()->isLoaded()){
        result = getParent()->read();
        if(!result){
            return T100FALSE;
        }
    }

    switch(getParent()->m_item->type){
    case T100Assembly::T100CONSTANT_INTEGER:
        {
            op.LENGTH       = 0;
            op.DATA_TYPE    = T100DATA_INTEGER;
            op.PREFIX_TYPE  = getParent()->m_type;

            op.VALUE        = std::stoll(getParent()->m_item->value.to_wstring().c_str(), T100NULL, 0);

            getParent()->setLoaded(T100FALSE);
            return T100TRUE;
        }
        break;
    case T100Assembly::T100CONSTANT_FLOAT:
        {
            if(P_NONE != getParent()->m_type){
                //
                return T100FALSE;
            }

            op.LENGTH       = 0;
            op.DATA_TYPE    = T100DATA_FLOAT;
            op.PREFIX_TYPE  = getParent()->m_type;

            op.VALUE        = std::stof(getParent()->m_item->value.to_wstring().c_str());

            getParent()->setLoaded(T100FALSE);
            return T100TRUE;
        }
        break;
    case T100Assembly::T100CONSTANT_STRING:
        {
            getParent()->m_token->type  = T100Component::T100TOKEN_ERROR;
            getParent()->m_token->err   = T100Assembly::T100ERROR_SENTENCE;
            //
            return T100FALSE;
        }
        break;
    case T100Component::T100TOKEN_EOF:
        {
            getParent()->m_token->type  = T100Component::T100TOKEN_ERROR;
            getParent()->m_token->err   = T100Assembly::T100ERROR_SENTENCE;
            //
            return T100FALSE;
        }
        break;
    default:
        getParent()->m_token->type  = T100Component::T100TOKEN_ERROR;
        getParent()->m_token->err   = T100Assembly::T100ERROR_SENTENCE;
        //
        return T100FALSE;
    }

    return T100FALSE;
}

}
