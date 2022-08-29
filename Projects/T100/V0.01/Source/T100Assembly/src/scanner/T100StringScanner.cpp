#include "T100StringScanner.h"

T100StringScanner::T100StringScanner()
{
    //ctor
    T100Scanner::clear();
}

T100StringScanner::~T100StringScanner()
{
    //dtor
}

T100VOID T100StringScanner::setSource(T100Scanner* obj)
{
    m_scanner   = dynamic_cast<T100CharScanner*>(obj);
}

T100Scanner* T100StringScanner::getSource()
{
    return m_scanner;
}

T100StringToken* T100StringScanner::getToken()
{
    return m_token;
}

T100CharToken* T100StringScanner::getItem()
{
    return &m_item;
}

T100VOID T100StringScanner::clear()
{
    m_token->clear();
}

T100BOOL T100StringScanner::append()
{
    T100CHAR ch;

    ch = m_item.value;
    m_token->value += ch;

    //m_token->bytes.insert(m_token->bytes.end(), m_item.bytes.begin(), m_item.bytes.end());

    return T100TRUE;
}

T100BOOL T100StringScanner::read()
{
    T100BOOL    result      = T100FALSE;

    result = m_scanner->next(m_item);

    if(result){
        setLoaded(T100TRUE);
    }else{

    }

    return result;
}

T100BOOL T100StringScanner::next(T100Token& token)
{
    m_token = (T100StringToken*)&token;
    clear();

    return run();
}

T100BOOL T100StringScanner::run()
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
                //T100Log::info(T100AssemblyHint::string_hint(getToken(), T100STRINGSCAN_STRING_READ_FAILURE));
                return T100FALSE;
            }
        }

        result = classify();
        if(result){
            //T100AssemblyLog::info(T100LOG_STRING, T100AssemblyHint::string_hint(getToken(), T100STRINGSCAN_STRING_READ_SUCCESS));
            return T100TRUE;
        }

        if(m_item.eof){
            //T100AssemblyLog::info(T100LOG_STRING, T100AssemblyHint::string_hint(getToken(), T100STRINGSCAN_STRING_READ_SUCCESS));
            return T100TRUE;
        }
    }while(T100TRUE);

    return T100FALSE;
}

T100BOOL T100StringScanner::classify()
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

T100BOOL T100StringScanner::isOperator()
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
