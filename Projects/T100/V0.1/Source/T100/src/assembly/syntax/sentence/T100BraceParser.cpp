#include "T100BraceParser.h"

#include "T100AssemblyCommon.h"
#include "T100SentenceBase.h"

namespace T100SentenceBase{

T100BraceParser::T100BraceParser(T100SentenceBase* base)
    :T100ParserBase(base)
{
    //ctor
}

T100BraceParser::~T100BraceParser()
{
    //dtor
}

T100BOOL T100BraceParser::parse(::T100SentenceBase::T100OPERATOR_COMPLEXUS& op)
{
    T100BOOL        result          = T100FALSE;

    getParent()->setLoaded(T100FALSE);
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
    case T100Assembly::T100CHAR_POUND:
        {
            getParent()->m_type     = P_VALUE;
            getParent()->setLoaded(T100FALSE);
            goto READ_NEXT;
        }
        break;
    case T100Assembly::T100CHAR_EMAIL:
        {
            getParent()->m_type     = P_ADDRESS;
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
        {
            result = getParent()->getRegisterParser().parse(op.BASE);
            if(!result){
                return T100FALSE;
            }
            goto READ_NEXT;
        }
        break;
    case T100Assembly::T100CONSTANT_INTEGER:
        {
            op.BASE.USED    = T100TRUE;
            result = getParent()->getExpressionParser().parse(op.BASE);
            if(!result){
                return T100FALSE;
            }

            getParent()->setLoaded(T100FALSE);
            goto READ_NEXT;
        }
        break;
    case T100Assembly::T100KEYWORD_VARIABLE:
        {
            op.BASE.USED    = T100TRUE;
            result = getParent()->getVariableParser().parse(op.BASE);
            if(!result){
                return T100FALSE;
            }
            goto READ_NEXT;
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
    case T100Component::T100TOKEN_SPACE:
        {
            getParent()->setLoaded(T100FALSE);
            goto READ_NEXT;
        }
        break;
    case T100Assembly::T100CHAR_COLON:
        {
            getParent()->setLoaded(T100FALSE);
            //test
            result = getParent()->getOperatorParser().parse(op.OPERATOR);
            if(!result){
                return T100FALSE;
            }
            goto READ_NEXT;
        }
        break;
    case T100Assembly::T100CHAR_CLOSED_BRACE:
        {
            getParent()->setLoaded(T100FALSE);
            return T100TRUE;
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
