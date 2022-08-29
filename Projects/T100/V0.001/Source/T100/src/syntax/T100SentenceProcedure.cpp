#include "T100SentenceProcedure.h"

#include "T100AssemblyError.h"
#include "T100FileData.h"
#include "T100SentenceScan.h"


T100SentenceProcedure::T100SentenceProcedure(T100SentenceScan* scan)
    :T100Sentence(scan)
{
    //ctor
}

T100SentenceProcedure::~T100SentenceProcedure()
{
    //dtor
}

T100BOOL T100SentenceProcedure::parse()
{
    T100BOOL    result      = T100TRUE;

    result = parseSetup();

    if(result){
        type            = T100SENTENCE_PROCEDURE;
        m_token->type   = T100SENTENCE_PROCEDURE;

        T100PROCEDURE_DEFINE*   pd = T100NEW T100PROCEDURE_DEFINE;

        pd->name        = name;

        T100Code::setProcedureDefine(name, pd);
    }

    return result;
}

T100BOOL T100SentenceProcedure::parseSetup()
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
            T100AssemblyError::error(T100AssemblyHint::sentence_hint(this, T100SENTENCE_PROCEDURE_SYNTAX_ERROR));
            return T100FALSE;
            break;
        }
    case T100TOKEN_SPACE:
        {
            setLoaded(T100FALSE);
            goto READ_NEXT;
            break;
        }
    case T100KEYWORD_PROCEDURE:
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
                    T100AssemblyError::error(T100AssemblyHint::sentence_hint(this, T100SENTENCE_PROCEDURE_SYNTAX_ERROR));
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

    T100AssemblyError::error(T100AssemblyHint::sentence_hint(this, T100SENTENCE_PROCEDURE_SYNTAX_ERROR));
    return T100FALSE;
}

T100BOOL T100SentenceProcedure::build(T100FileData* code)
{
    return code->createSegment(this);
}

T100STDSTRING T100SentenceProcedure::tostring()
{
    T100STDSTRING   result;

    result  = data.to_std_string();

    result  += " = ";
    result  += name.to_std_string();

    return result;
}
