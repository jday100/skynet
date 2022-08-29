#include "T100SentenceCode.h"

#include "T100AssemblyError.h"
#include "T100CodeNew.h"
#include "T100FileData.h"
#include "T100SentenceScan.h"


T100SentenceCode::T100SentenceCode(T100SentenceScan* scan)
    :T100Sentence(scan)
{
    //ctor
}

T100SentenceCode::~T100SentenceCode()
{
    //dtor
}

T100BOOL T100SentenceCode::parse()
{
    T100BOOL    result      = T100FALSE;

    result = parseSetup();

    if(result){
        type            = T100SENTENCE_CODE;
        m_token->type   = T100SENTENCE_CODE;
    }

    return result;
}

T100BOOL T100SentenceCode::parseSetup()
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
            T100AssemblyError::error(T100AssemblyHint::sentence_hint(this, T100SENTENCE_CODE_SYNTAX_ERROR));
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
                    name    = m_item->data;
                    setLoaded(T100FALSE);
                    goto READ_NEXT;
                }else{
                    T100AssemblyError::error(T100AssemblyHint::sentence_hint(this, T100SENTENCE_CODE_SYNTAX_ERROR));
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

            if(T100Code::m_code_default){
                T100AssemblyError::error(T100AssemblyHint::sentence_hint(this, T100SENTENCE_CODE_SYNTAX_ERROR));
                return T100FALSE;
            }else{
                T100Code::m_code_default    = T100TRUE;
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
                    location = std::stoll(m_item->data.to_std_string().c_str(), T100NULL, 0);

                    setLoaded(T100FALSE);
                    goto READ_NEXT;
                }else{
                    T100AssemblyError::error(T100AssemblyHint::sentence_hint(this, T100SENTENCE_CODE_SYNTAX_ERROR));
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
                    length = std::stoi(m_item->data.to_std_string());

                    setLoaded(T100FALSE);
                    goto READ_NEXT;
                }else{
                    T100AssemblyError::error(T100AssemblyHint::sentence_hint(this, T100SENTENCE_CODE_SYNTAX_ERROR));
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

    T100AssemblyError::error(T100AssemblyHint::sentence_hint(this, T100SENTENCE_CODE_SYNTAX_ERROR));
    return T100FALSE;
}

T100BOOL T100SentenceCode::build(T100FileData* code)
{
    return code->createSegment(this);
}
