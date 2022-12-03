#include "T100ComplexusParser.h"

#include "T100AssemblyCommon.h"
#include "T100SentenceBase.h"

namespace T100SentenceBase{

T100ComplexusParser::T100ComplexusParser(T100SentenceBase* base)
    :T100ParserBase(base)
{
    //ctor
}

T100ComplexusParser::~T100ComplexusParser()
{
    //dtor
}

T100BOOL T100ComplexusParser::parse(T100OPERATOR_COMPLEXUS& op)
{
    T100BOOL        result          = T100FALSE;

    getParent()->m_type     = P_NONE;

READ_NEXT:
    if(!getParent()->isLoaded()){
        result = getParent()->read();
        if(!result){
            return T100FALSE;
        }
    }

    switch(getParent()->m_item->type){
    case T100Component::T100TOKEN_BR:
        {
            getParent()->m_token->type  = T100Component::T100TOKEN_ERROR;
            getParent()->m_token->err   = T100Assembly::T100ERROR_SENTENCE;
            //
            return T100FALSE;
        }
        break;
    case T100Component::T100TOKEN_SPACE:
        {
            getParent()->setLoaded(T100FALSE);
            goto READ_NEXT;
        }
        break;
    case T100Assembly::T100CHAR_POUND:
        {
            getParent()->m_type     = P_VALUE;
            getParent()->setLoaded(T100FALSE);
            goto READ_NEXT;
        }
        break;
    case T100Assembly::T100CHAR_EMAIL:
        {
            getParent()->type   = P_ADDRESS;
            getParent()->setLoaded(T100FALSE);
            goto READ_NEXT;
        }
        break;
    case T100Assembly::T100KEYWORD_COR:
    case T100Assembly::T100KEYWORD_CBR:
    case T100Assembly::T100KEYWORD_CCR:
    case T100Assembly::T100KEYWORD_SSR:
    case T100Assembly::T100KEYWORD_SPR:
    case T100Assembly::T100KEYWORD_AAR:
    case T100Assembly::T100KEYWORD_ABR:
    case T100Assembly::T100KEYWORD_ACR:
    case T100Assembly::T100KEYWORD_ADR:
    case T100Assembly::T100KEYWORD_ACF:
    case T100Assembly::T100KEYWORD_AMF:
    case T100Assembly::T100KEYWORD_AOF:
        {
            op.BASE.USED        = T100FALSE;
            op.PREFIX_TYPE      = P_NONE;
            op.TYPE             = ::T100SentenceBase::T100OPERATOR_ONE_ONE;
            return getParent()->getRegisterParser().parse(op.OPERATOR);
        }
        break;
    case T100Assembly::T100CONSTANT_INTEGER:
    case T100Assembly::T100CONSTANT_FLOAT:
        {
            op.OPERATOR.USED    = T100TRUE;
            op.PREFIX_TYPE      = P_NONE;
            op.TYPE             = ::T100SentenceBase::T100OPERATOR_ONE_ONE;
            return getParent()->getExpressionParser().parse(op.OPERATOR);
        }
        break;
    case T100Assembly::T100KEYWORD_VARIABLE:
        {
            op.OPERATOR.USED    = T100TRUE;
            op.PREFIX_TYPE      = P_NONE;
            op.TYPE             = ::T100SentenceBase::T100OPERATOR_ONE_ONE;
            return getParent()->getVariableParser().parse(op.OPERATOR);
        }
        break;
    case T100Assembly::T100KEYWORD_LABEL:
        {
            op.OPERATOR.USED    = T100TRUE;
            return getParent()->getLabelParser().parse(op.OPERATOR);
        }
        break;
    case T100Assembly::T100CHAR_OPEN_BRACE:
        {
            op.USED             = T100TRUE;
            op.PREFIX_TYPE      = getParent()->m_type;
            op.TYPE             = ::T100SentenceBase::T100OPERATOR_THREE_THREE;
            return getParent()->getBraceParser().parse(op);
        }
        break;
    case T100Component::T100TOKEN_EOF:
        {
            getParent()->m_token->type      = T100Component::T100TOKEN_ERROR;
            getParent()->m_token->err       = T100Assembly::T100ERROR_SENTENCE;
            //
            return T100FALSE;
        }
        break;
    default:
        getParent()->m_token->type      = T100Component::T100TOKEN_ERROR;
        getParent()->m_token->err       = T100Assembly::T100ERROR_SENTENCE;
        //
        return T100FALSE;
    }
    return T100FALSE;
}

}
