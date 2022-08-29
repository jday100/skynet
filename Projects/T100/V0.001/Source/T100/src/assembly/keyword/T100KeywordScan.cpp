#include "T100KeywordScan.h"

#include "T100AsmCommon.h"


T100KeywordScan::T100KeywordScan()
{
    //ctor
}

T100KeywordScan::~T100KeywordScan()
{
    //dtor
}

T100BOOL T100KeywordScan::open(T100String& file)
{
    m_scan = T100NEW T100StringScan();
    return m_scan->open(file);
}

T100BOOL T100KeywordScan::close()
{
    T100BOOL result;

    result = m_scan->close();

    if(result){
        T100DELETE(m_scan);
        m_scan = T100NULL;
    }

    return result;
}

T100KeywordToken* T100KeywordScan::getToken()
{
    return m_token;
}

T100StringToken* T100KeywordScan::getItem()
{
    return &m_item;
}

T100BOOL T100KeywordScan::append()
{
    m_token->row    = m_item.row;
    //m_token->data.append(m_item.data);
    m_token->data += m_item.data;

    m_token->bytes.insert(m_token->bytes.end(), m_item.bytes.begin(), m_item.bytes.end());

    return T100TRUE;
}

T100BOOL T100KeywordScan::read()
{
    T100BOOL    result      = T100FALSE;

    result = m_scan->next(m_item);
    if(!result){

    }else{
        setLoaded(T100TRUE);
    }

    return result;
}

T100BOOL T100KeywordScan::next(IToken& token)
{
    m_token = (T100KeywordToken*)&token;
    m_token->clear();

    return run();
}

T100BOOL T100KeywordScan::run()
{
    T100BOOL    result      = T100FALSE;

READ_NEXT:
    if(!isLoaded()){
        result = read();
        if(!result){
            return T100FALSE;
        }
    }

    switch(m_item.type)
    {
    case T100TOKEN_SPACE:
        {
            setLoaded(T100FALSE);
            goto READ_NEXT;

            break;
        }
    case T100CHAR_UPPER:
        {
            result = parseUpper();

            break;
        }
    case T100CHAR_LOWER:
        {
            result = parseLower();

            break;
        }
    case T100CHAR_DIGIT:
        {
            result = parseDigit();

            break;
        }
    case T100CHAR_DOUBLE_QUOTES:
        {
            result = parseQuotes();

            break;
        }
    case T100CHAR_SLASH:
        {
            result = parseSlash();

            break;
        }
    case T100TOKEN_BR:
        {
            m_token->type   = T100TOKEN_BR;
            setLoaded(T100FALSE);
            result = T100TRUE;

            break;
        }
    case T100TOKEN_EOF:
        {
            m_token->type   = T100TOKEN_EOF;
            m_token->eof    = m_item.eof;
            m_token->row    = m_item.row;
            result          = T100TRUE;

            break;
        }
    default:
        m_token->type   = m_item.type;
        append();
        setLoaded(T100FALSE);
        result = T100TRUE;
    }

    if(result){
        T100AssemblyLog::info(T100LOG_KEYWORD, T100AssemblyHint::keyword_hint(getToken(), T100KEYWORDSCAN_KEYWORD_READ_SUCCESS));
    }

    return result;
}

T100BOOL T100KeywordScan::parseUpper()
{
    T100BOOL    result      = T100FALSE;

    append();
    setLoaded(T100FALSE);

    do{
        if(!isLoaded()){
            result = read();
            if(!result){
                return T100FALSE;
            }
        }

        switch(m_item.type){
        case T100CHAR_UPPER:
        case T100CHAR_UNDERLINE:
        case T100CHAR_DIGIT:
            {
                append();
                setLoaded(T100FALSE);

                break;
            }
        case T100CHAR_COLON:
            {
                m_token->type   = classify();
                if(T100TOKEN_NONE == m_token->type){
                    m_token->type = T100KEYWORD_LABEL;
                    setLoaded(T100FALSE);
                }

                return T100TRUE;
                break;
            }
        default:
            m_token->type   = classify();
            if(T100TOKEN_NONE == m_token->type){
                m_token->type = T100KEYWORD_LABEL;
            }
            return T100TRUE;
        };
    }while(T100TRUE);

    return result;
}

T100BOOL T100KeywordScan::parseLower()
{
    T100BOOL    result      = T100FALSE;

    append();
    setLoaded(T100FALSE);

    do{
        if(!isLoaded()){
            result = read();
            if(!result){
                return T100FALSE;
            }
        }

        switch(m_item.type)
        {
        case T100CHAR_UPPER:
        case T100CHAR_LOWER:
        case T100CHAR_UNDERLINE:
        case T100CHAR_DIGIT:
            {
                append();
                setLoaded(T100FALSE);

                break;
            }
        default:
            m_token->type   = T100KEYWORD_VARIABLE;
            return T100TRUE;
        }
    }while(T100TRUE);

    return result;
}

T100BOOL T100KeywordScan::parseDigit()
{
    T100BOOL    result      = T100FALSE;

    append();

    result = read();
    if(!result){
        return T100FALSE;
    }

    if(m_item.type == T100CHAR_DOT){
        append();

        result = read();
        if(!result){
            return T100FALSE;
        }

        if(m_item.type == T100CHAR_DIGIT){
            append();
            m_token->type   = T100CONSTANT_FLOAT;
            result = read();
            if(!result){
                return T100FALSE;
            }

            if(m_item.type == T100CHAR_DOT){
                result = T100FALSE;
            }else{
                result = T100TRUE;
            }
        }else{
            result = T100FALSE;
        }
    }else{
        m_token->type   = T100CONSTANT_INTEGER;
        result = T100TRUE;
    }

    return result;
}

T100BOOL T100KeywordScan::parseQuotes()
{
    T100BOOL    result      = T100FALSE;

    append();
    setLoaded(T100FALSE);

    do{
        if(!isLoaded()){
            result = read();
            if(!result){
                return T100FALSE;
            }
        }

        switch(m_item.type){
        case T100CHAR_DOUBLE_QUOTES:
            {
                m_token->type   = T100CONSTANT_STRING;
                append();
                setLoaded(T100FALSE);

                return T100TRUE;
                break;
            }
        case T100TOKEN_EOF:
        case T100TOKEN_BR:
            {
                m_token->err    = T100ERROR_KEYWORD;
                return T100FALSE;

                break;
            }
        default:
            append();
            setLoaded(T100FALSE);
            break;
        };
    }while(T100TRUE);

    return result;
}

T100BOOL T100KeywordScan::parseSlash()
{
    T100BOOL    result      = T100FALSE;

    append();

    result = read();
    if(!result){
        return T100FALSE;
    }

    switch(m_item.type){
    case T100CHAR_SLASH:
        {
            append();
            setLoaded(T100FALSE);

            do{
                if(!isLoaded()){
                    result = read();
                    if(!result){
                        return T100FALSE;
                    }
                }

                switch(m_item.type){
                case T100TOKEN_BR:
                    {
                        m_token->type   = T100KEYWORD_COMMENT;
                        return T100TRUE;

                        break;
                    }
                case T100TOKEN_EOF:
                    {
                        m_token->type   = T100KEYWORD_COMMENT;
                        return T100TRUE;

                        break;
                    }
                default:
                    append();
                    setLoaded(T100FALSE);
                };
            }while(T100TRUE);

            break;
        }
    default:
        result = T100TRUE;
    };

    return result;
}

T100TOKEN_TYPE T100KeywordScan::classify()
{
    T100TOKEN_TYPE  result      = T100TOKEN_NONE;
    T100String      key;

    key = m_token->data;

    result = m_keywords.find(key);

    return result;
}
