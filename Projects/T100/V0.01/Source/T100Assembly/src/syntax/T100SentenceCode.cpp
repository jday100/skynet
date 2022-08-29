#include "T100SentenceCode.h"

#include "T100ProduceInfo.h"


T100SentenceCode::T100SentenceCode(T100SentenceScanner* scanner)
    :T100Sentence(scanner)
{
    //ctor
}

T100SentenceCode::~T100SentenceCode()
{
    //dtor
}

T100BOOL T100SentenceCode::parse()
{
    T100BOOL        result          = T100TRUE;

    result = parseConfig();

    if(result){
        type            = T100SENTENCE_CODE;
        m_token->type   = T100SENTENCE_CODE;
    }

    return result;
}

T100BOOL T100SentenceCode::parseConfig()
{
    T100BOOL    result      = T100FALSE;

READ_NEXT:
    if(!isLoaded()){
        result = read();
        if(!result){
            return T100FALSE;
        }
    }

    switch(m_item->type)
    {
    case T100TOKEN_BR:
        {
            return T100TRUE;
            break;
        }
    case T100TOKEN_EOF:
        {
            m_token->type       = T100TOKEN_ERROR;
            m_token->err        = T100ERROR_SENTENCE;
            //T100AssemblyError::error(T100AssemblyHint::sentence_hint(this, T100SENTENCE_CODE_SYNTAX_ERROR));
            return T100FALSE;
            break;
        }
    case T100TOKEN_SPACE:
        {
            setLoaded(T100FALSE);
            goto READ_NEXT;
            break;
        }
    case T100KEYWORD_VIRTUAL:
        {
            isVirtual   = T100TRUE;
            setLoaded(T100FALSE);
            goto READ_NEXT;
            break;
        }
    case T100KEYWORD_CODE:
        {
            result = read();
            if(!result){
                return T100FALSE;
            }

            if(T100CHAR_EQUAL == m_item->type){
                result = read();
                if(!result){
                    return T100FALSE;
                }

                if(T100KEYWORD_LABEL == m_item->type){
                    name    = m_item->value;
                    setLoaded(T100FALSE);
                    goto READ_NEXT;
                }else{
                    //T100AssemblyError::error(T100AssemblyHint::sentence_hint(this, T100SENTENCE_CODE_SYNTAX_ERROR));
                    return T100FALSE;
                }
            }else{
                goto READ_NEXT;
            }
            break;
        }
    case T100KEYWORD_DEFAULT:
        {
            isDefault   = T100TRUE;
            setLoaded(T100FALSE);

            if(T100ProduceInfo::m_code_default){
                //T100AssemblyError::error(T100AssemblyHint::sentence_hint(this, T100SENTENCE_CODE_SYNTAX_ERROR));
                return T100FALSE;
            }else{
                T100ProduceInfo::m_code_default    = T100TRUE;
            }

            goto READ_NEXT;
            break;
        }
    case T100KEYWORD_SHARE:
        {
            isShare     = T100TRUE;
            setLoaded(T100FALSE);
            goto READ_NEXT;
        }
    case T100KEYWORD_LOCATION:
        {
            result = read();
            if(!result){
                return T100FALSE;
            }

            if(T100CHAR_EQUAL == m_item->type){
                result = read();
                if(!result){
                    return T100FALSE;
                }

                if(T100CONSTANT_INTEGER == m_item->type){
                    //location = std::stoi(m_item->data.to_std_string());
                    location = std::stoll(m_item->value.to_wstring().c_str(), T100NULL, 0);

                    setLoaded(T100FALSE);
                    goto READ_NEXT;
                }else{
                    //T100AssemblyError::error(T100AssemblyHint::sentence_hint(this, T100SENTENCE_CODE_SYNTAX_ERROR));
                    return T100FALSE;
                }
            }else{
                goto READ_NEXT;
            }
            break;
        }
    case T100KEYWORD_LENGTH:
        {
            result = read();
            if(!result){
                return T100FALSE;
            }

            if(T100CHAR_EQUAL == m_item->type){
                result = read();
                if(!result){
                    return T100FALSE;
                }

                if(T100CONSTANT_INTEGER == m_item->type){
                    length = std::stoi(m_item->value.to_wstring());

                    setLoaded(T100FALSE);
                    goto READ_NEXT;
                }else{
                    //T100AssemblyError::error(T100AssemblyHint::sentence_hint(this, T100SENTENCE_CODE_SYNTAX_ERROR));
                    return T100FALSE;
                }
            }else{
                goto READ_NEXT;
            }
            break;
        }
    case T100KEYWORD_COMMENT:
        {
            return T100TRUE;
        }
    }

    //T100AssemblyError::error(T100AssemblyHint::sentence_hint(this, T100SENTENCE_CODE_SYNTAX_ERROR));
    return T100FALSE;
}

T100BOOL T100SentenceCode::build(T100BuildInfo* info)
{
    return info->openSegment(this);
}
