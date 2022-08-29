#include "T100StringScan.h"

T100StringScan::T100StringScan()
{
    //ctor
}

T100StringScan::~T100StringScan()
{
    //dtor
}

T100BOOL T100StringScan::open(T100String& file)
{
    m_scan = T100NEW T100CharScan();
    return m_scan->open(file);
}

T100BOOL T100StringScan::close()
{
    T100BOOL result;

    result = m_scan->close();

    if(result){
        T100DELETE(m_scan);
        m_scan = T100NULL;
    }

    return result;
}

T100StringToken* T100StringScan::getToken()
{
    return m_token;
}

T100CharToken* T100StringScan::getItem()
{
    return &m_item;
}

T100VOID T100StringScan::clear()
{
    m_token->clear();
}

T100BOOL T100StringScan::append()
{
    T100CHAR ch;

    ch = m_item.data;
    m_token->data.append(ch);

    m_token->bytes.insert(m_token->bytes.end(), m_item.bytes.begin(), m_item.bytes.end());

    return T100TRUE;
}

T100BOOL T100StringScan::read()
{
    T100BOOL    result      = T100FALSE;

    result = m_scan->next(m_item);

    if(result){
        setLoaded(T100TRUE);
    }else{

    }

    return result;
}

T100BOOL T100StringScan::next(IToken& token)
{
    m_token = (T100StringToken*)&token;
    clear();

    return run();
}

T100BOOL T100StringScan::run()
{
    T100BOOL    result      = T100FALSE;

    if(isLoaded()){
        if(m_item.type == T100TOKEN_EOF){
            m_token->type   = T100TOKEN_EOF;
            m_token->eof    = T100TRUE;
            m_token->row    = m_item.row;
            return T100TRUE;
        }

        append();
        m_token->type   = m_item.type;
        m_token->row    = m_item.row;
        m_type          = m_item.type;
        setLoaded(T100FALSE);
    }

    do{
        if(!isLoaded()){
            result = read();
            if(!result){
                T100Log::info(T100AssemblyHint::string_hint(getToken(), T100STRINGSCAN_STRING_READ_FAILURE));
                return T100FALSE;
            }
        }

        result = classify();
        if(result){
            T100AssemblyLog::info(T100LOG_STRING, T100AssemblyHint::string_hint(getToken(), T100STRINGSCAN_STRING_READ_SUCCESS));
            return T100TRUE;
        }

        if(m_item.eof){
            T100AssemblyLog::info(T100LOG_STRING, T100AssemblyHint::string_hint(getToken(), T100STRINGSCAN_STRING_READ_SUCCESS));
            return T100TRUE;
        }
    }while(T100TRUE);

    return T100FALSE;
}

T100BOOL T100StringScan::classify()
{
    if(T100TOKEN_NONE == m_type){
        m_token->type   = m_item.type;
        m_type          = m_item.type;
        append();
        setLoaded(T100FALSE);
        return T100FALSE;
    }else if(m_type == m_item.type){
        if(isOperator()){
            return T100TRUE;
        }else{
            append();
            setLoaded(T100FALSE);
            return T100FALSE;
        }
    }else{
        return T100TRUE;
    }

    return T100TRUE;
}

T100BOOL T100StringScan::isOperator()
{
    T100BOOL    result      = T100FALSE;

    switch(m_item.type){
    case T100CHAR_DOUBLE_QUOTES:
    case T100CHAR_POUND:
    case T100CHAR_DOLLAR:
    case T100CHAR_PERCENT:
    case T100CHAR_AND:
    case T100CHAR_OPEN_PARENS:
    case T100CHAR_CLOSED_PARENS:
    case T100CHAR_ASTERISK:
    case T100CHAR_PLUS:
    case T100CHAR_MINUS:
    case T100CHAR_DOT:
    case T100CHAR_SLASH:
    case T100CHAR_COLON:
    case T100CHAR_EMAIL:
    case T100CHAR_OPEN_BRACKETS:
    case T100CHAR_CLOSED_BRACKETS:
    case T100CHAR_UNDERLINE:
        {
            result = T100TRUE;

            break;
        }
    case T100TOKEN_EOF:
        {
            result = T100TRUE;

            break;
        }
    };

    return result;
}
