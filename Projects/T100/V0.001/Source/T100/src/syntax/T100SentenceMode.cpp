#include "T100SentenceMode.h"

#include "T100AssemblyError.h"
#include "T100FileData.h"
#include "T100SentenceScan.h"


T100SentenceMode::T100SentenceMode(T100SentenceScan* scan)
    :T100Sentence(scan)
{
    //ctor
}

T100SentenceMode::~T100SentenceMode()
{
    //dtor
}

T100BOOL T100SentenceMode::parse()
{
    T100BOOL    result      = T100FALSE;

    result = parseSetup();

    if(result){
        type            = T100SENTENCE_MODE;
        m_token->type   = T100SENTENCE_MODE;
    }

    return result;
}

T100BOOL T100SentenceMode::parseSetup()
{
    T100BOOL    result      = T100FALSE;

    setLoaded(T100FALSE);

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
    case T100TOKEN_SPACE:
        {
            setLoaded(T100FALSE);
            goto READ_NEXT;
        }
    case T100TOKEN_EOF:
        {
            m_token->type   = T100TOKEN_ERROR;
            m_token->err    = T100ERROR_SENTENCE;
            T100AssemblyError::error(T100AssemblyHint::sentence_hint(this, T100SENTENCE_MODE_SYNTAX_ERROR));
            return T100FALSE;
            break;
        }
    case T100KEYWORD_REAL:
        {
            mode        = T100MODE_REAL;
            setLoaded(T100FALSE);
            goto READ_NEXT;
        }
    case T100KEYWORD_NORMAL:
        {
            setLoaded(T100FALSE);
            goto READ_NEXT;
        }
    case T100KEYWORD_VIRTUAL:
        {
            mode        = T100MODE_VIRTUAL;
            setLoaded(T100FALSE);
            goto READ_NEXT;
        }
    case T100KEYWORD_TINY:
        {
            istiny          = T100TRUE;
            segment_type    = T100TYPE_TINY;
            setLoaded(T100FALSE);
            goto READ_NEXT;
        }
    case T100KEYWORD_SMALL:
        {
            segment_type    = T100TYPE_SMALL;
            setLoaded(T100FALSE);
            goto READ_NEXT;
        }
    case T100KEYWORD_BIG:
        {
            segment_type    = T100TYPE_BIG;
            setLoaded(T100FALSE);
            goto READ_NEXT;
        }
    case T100KEYWORD_COMMENT:
        return T100TRUE;
    }

    T100AssemblyError::error(T100AssemblyHint::sentence_hint(this, T100SENTENCE_MODE_SYNTAX_ERROR));
    return T100FALSE;
}

T100BOOL T100SentenceMode::build(T100FileData* code)
{
    code->setTiny(istiny);
    code->setMode(mode);
    code->setType(segment_type);

    return T100TRUE;
}
