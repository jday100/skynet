#include "T100SentenceMode.h"

#include "T100AssemblyHint.h"
#include "T100AssemblyError.h"
#include "T100ProduceInfo.h"

namespace T100Assembly{

T100SentenceMode::T100SentenceMode(T100SentenceScanner* scanner)
    :T100Sentence(scanner)
{
    //ctor
}

T100SentenceMode::~T100SentenceMode()
{
    //dtor
}

T100VOID T100SentenceMode::init()
{
    T100ProduceInfo::m_token_names[T100SENTENCE_MODE] = L"T100SentenceMode";
}

T100BOOL T100SentenceMode::parse()
{
    T100BOOL        result          = T100TRUE;

    result = parseConfig();

    if(result){
        type            = T100SENTENCE_MODE;
        m_token->type   = T100SENTENCE_MODE;
    }

    return result;
}

T100BOOL T100SentenceMode::parseConfig()
{
    T100BOOL        result          = T100FALSE;

    setLoaded(T100FALSE);

READ_NEXT:
    if(!isLoaded()){
        result = read();
        if(!result){
            return T100FALSE;
        }
    }

    switch(m_item->type){
    case T100Component::T100TOKEN_BR:
        {
            return T100TRUE;
        }
        break;
    case T100Component::T100TOKEN_SPACE:
        {
            setLoaded(T100FALSE);
            goto READ_NEXT;
        }
        break;
    case T100Component::T100TOKEN_EOF:
        {
            m_token->type   = T100Component::T100TOKEN_ERROR;
            m_token->err    = T100ERROR_SENTENCE;
            //T100AssemblyError::error(T100AssemblyHint::sentence_hint(this, T100SENTENCE_MODE_SYNTAX_ERROR));
            return T100FALSE;
        }
        break;
    case T100KEYWORD_REAL:
        {
            mode        = T100MODE_REAL;
            setLoaded(T100FALSE);

            if(T100ProduceInfo::setMode(T100MODE_REAL)){

            }else{
                return T100FALSE;
            }

            goto READ_NEXT;
        }
        break;
    case T100KEYWORD_NORMAL:
        {
            setLoaded(T100FALSE);
            goto READ_NEXT;
        }
        break;
    case T100KEYWORD_VIRTUAL:
        {
            mode        = T100MODE_VIRTUAL;
            setLoaded(T100FALSE);

            if(T100ProduceInfo::setMode(T100MODE_VIRTUAL)){

            }else{
                return T100FALSE;
            }

            goto READ_NEXT;
        }
        break;
    case T100KEYWORD_COMMENT:
        {
            return T100TRUE;
        }
        break;
    }

    //T100AssemblyError::error(T100AssemblyHint::sentence_hint(this, T100SENTENCE_MODE_SYNTAX_ERROR));
    return T100FALSE;
}

T100BOOL T100SentenceMode::build(T100BuildInfo* info)
{
    return T100TRUE;
}

}
