#include "T100SentenceProcedure.h"

#include "T100ProduceInfo.h"
#include "T100ProcedureDrawer.h"

namespace T100Assembly{

T100SentenceProcedure::T100SentenceProcedure(T100SentenceScanner* scanner)
    :T100Sentence(scanner)
{
    //ctor
}

T100SentenceProcedure::~T100SentenceProcedure()
{
    //dtor
}

T100BOOL T100SentenceProcedure::parse()
{
    T100BOOL        result          = T100TRUE;

    result = parseConfig();

    if(result){
        type            = T100SENTENCE_PROCEDURE;
        m_token->type   = T100SENTENCE_PROCEDURE;

        result = setDefine(name);
    }

    return result;
}

T100BOOL T100SentenceProcedure::parseConfig()
{
    T100BOOL        result          = T100FALSE;

READ_NEXT:
    if(!isLoaded()){
        result = read();
        if(!result){
            return T100FALSE;
        }
    }

    switch(m_item->type){
    case T100TOKEN_BR:
        {
            return T100TRUE;
        }
        break;
    case T100TOKEN_EOF:
        {
            m_token->type   = T100TOKEN_ERROR;
            m_token->err    = T100ERROR_SENTENCE;
            T100AssemblyError::error(T100AssemblyHint::sentence_hint(this, T100SENTENCE_PROCEDURE_SYNTAX_ERROR));
            return T100FALSE;
        }
        break;
    case T100TOKEN_SPACE:
        {
            setLoaded(T100FALSE);
            goto READ_NEXT;
        }
        break;
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
                    name        = m_item->value;
                    setLoaded(T100FALSE);
                    goto READ_NEXT;
                }else{
                    T100AssemblyError::error(T100AssemblyHint::sentence_hint(this, T100SENTENCE_PROCEDURE_SYNTAX_ERROR));
                    return T100FALSE;
                }
            }else{
                goto READ_NEXT;
            }
        }
        break;
    case T100KEYWORD_COMMENT:
        {
            return T100TRUE;
        }
        break;
    }

    T100AssemblyError::error(T100AssemblyHint::sentence_hint(this, T100SENTENCE_PROCEDURE_SYNTAX_ERROR));
    return T100FALSE;
}

T100BOOL T100SentenceProcedure::build(T100BuildInfo* info)
{
    return info->openSegment(this);
}

T100BOOL T100SentenceProcedure::setDefine(T100STRING& name)
{
    T100BOOL        result          = T100TRUE;

    T100PROCEDURE_DEFINE* pd = T100NEW T100PROCEDURE_DEFINE();

    pd->name    = name;

    result = T100ProduceInfo::getProcedureDrawer().setProcedureDefine(name, pd);

    if(!result){
        T100SAFE_DELETE(pd);
    }

    return result;
}

}
