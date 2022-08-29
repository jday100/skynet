#include "T100KeywordScanner.h"

#include "T100AssemblyCommon.h"


T100KeywordScanner::T100KeywordScanner()
{
    //ctor
    clear();
}

T100KeywordScanner::~T100KeywordScanner()
{
    //dtor
}

T100VOID T100KeywordScanner::setSource(T100Scanner* obj)
{
    m_scanner   = dynamic_cast<T100StringScanner*>(obj);
}

T100Scanner* T100KeywordScanner::getSource()
{
    return m_scanner;
}

T100KeywordToken* T100KeywordScanner::getToken()
{
    return m_token;
}

T100StringToken* T100KeywordScanner::getItem()
{
    return &m_item;
}

T100BOOL T100KeywordScanner::append()
{
    m_token->row    = m_item.row;
    m_token->value  += m_item.value;

    //m_token->bytes.insert(m_token->bytes.end(), m_item.bytes.begin(), m_item.bytes.end());

    return T100TRUE;
}

T100BOOL T100KeywordScanner::read()
{
    T100BOOL    result      = T100FALSE;

    result = m_scanner->next(m_item);
    if(!result){

    }else{
        setLoaded(T100TRUE);
    }

    return result;
}

T100BOOL T100KeywordScanner::next(T100Token& token)
{
    m_token = (T100KeywordToken*)&token;
    m_token->clear();

    return run();
}

T100BOOL T100KeywordScanner::run()
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
        //T100AssemblyLog::info(T100LOG_KEYWORD, T100AssemblyHint::keyword_hint(getToken(), T100KEYWORDSCAN_KEYWORD_READ_SUCCESS));
    }

    return result;
}

T100BOOL T100KeywordScanner::parseUpper()
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

T100BOOL T100KeywordScanner::parseLower()
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

T100BOOL T100KeywordScanner::parseDigit()
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

T100BOOL T100KeywordScanner::parseQuotes()
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

T100BOOL T100KeywordScanner::parseSlash()
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

T100TOKEN_TYPE T100KeywordScanner::classify()
{
    T100TOKEN_TYPE  result      = T100TOKEN_NONE;
    T100String      key;

    key = m_token->value;

    result = m_keywords.find(key);

    return result;
}
