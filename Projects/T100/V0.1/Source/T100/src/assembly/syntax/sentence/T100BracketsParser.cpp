#include "T100BracketsParser.h"

#include "T100AssemblyCommon.h"
#include "T100SentenceBase.h"

namespace T100SentenceBase{

T100BracketsParser::T100BracketsParser(T100SentenceBase* base)
    :T100ParserBase(base)
{
    //ctor
}

T100BracketsParser::~T100BracketsParser()
{
    //dtor
}

T100BOOL T100BracketsParser::parse(T100OPERATOR& op)
{
    T100BOOL        result          = T100FALSE;

    getParent()->setLoaded(T100FALSE);

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
            return T100TRUE;
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
    case T100Assembly::T100CHAR_OPEN_BRACKETS:
        {
            result = getParent()->read();
            if(!result){
                return T100FALSE;
            }

            if(T100Assembly::T100CONSTANT_INTEGER == getParent()->m_item->type){
                T100WORD        value;

                value = std::stoll(getParent()->m_item->value.to_wstring());

                result = getParent()->read();
                if(!result){
                    return T100FALSE;
                }

                if(T100Assembly::T100CHAR_CLOSED_BRACKETS == getParent()->m_item->type){
                    op.ISARRAY  = T100TRUE;
                    op.LENGTH   = value;
                    getParent()->setLoaded(T100FALSE);
                    return T100TRUE;
                }else{
                    getParent()->m_token->type  = T100Component::T100TOKEN_ERROR;
                    getParent()->m_token->err   = T100Assembly::T100ERROR_SENTENCE;
                    //
                    return T100FALSE;
                }
            }else{
                getParent()->m_token->type  = T100Component::T100TOKEN_ERROR;
                getParent()->m_token->err   = T100Assembly::T100ERROR_SENTENCE;
                //
                return T100FALSE;
            }
        }
        break;
    default:
        return T100TRUE;
    }

    return T100FALSE;
}

}
