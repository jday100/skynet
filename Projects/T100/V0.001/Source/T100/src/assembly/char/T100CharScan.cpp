#include "T100CharScan.h"


T100CharScan::T100CharScan()
{
    //ctor
}

T100CharScan::~T100CharScan()
{
    //dtor
}

T100BOOL T100CharScan::open(T100String& file)
{
    m_file = file;
    m_scan = T100NEW T100ByteScan();
    return m_scan->open(file);
}

T100BOOL T100CharScan::close()
{
    T100BOOL result;

    result = m_scan->close();

    if(result){
        T100DELETE(m_scan);
        m_scan = T100NULL;
    }

    return result;
}

T100CharToken* T100CharScan::getToken()
{
    return m_token;
}

T100ByteToken* T100CharScan::getItem()
{
    return &m_item;
}

T100VOID T100CharScan::clear()
{
    m_token->clear();
}

T100BOOL T100CharScan::append()
{
    T100BOOL    result      = T100FALSE;

    if(!read()){
        return T100FALSE;
    }

    switch(m_item.type){
    case T100BYTE_ASCII:
        {
            T100WORD_BITS data;

            data.WORD           = 0;
            data.BYTE0.BYTE     = m_item.data;

            m_token->data       = data.WORD;
            m_token->row        = m_row;
            m_token->bytes.push_back(m_item.data);
            m_token->type       = classify();

            result = T100TRUE;
            break;
        }
    case T100BYTE_ONE:
        {
            m_token->type   = T100TOKEN_ERROR;
            m_token->err    = T100ERROR_CHAR;
            result          = T100FALSE;
            T100AssemblyError::error(T100AssemblyHint::file_hint(m_file.to_std_string(), T100CHARSCAN_CHAR_CODING_ERROR));
            break;
        }
    case T100BYTE_TWO:
        {
            T100BYTE_BITS   source;
            T100WORD_BITS   target;

            target.WORD     = 0;
            source.BYTE     = m_item.data;

            target.BYTE0.BIT0       = source.BIT0;
            target.BYTE0.BIT1       = source.BIT1;
            target.BYTE0.BIT2       = source.BIT2;
            target.BYTE0.BIT3       = source.BIT3;
            //
            target.BYTE0.BIT4       = source.BIT4;

            m_token->bytes.push_back(m_item.data);

            if(!read()){
                m_token->type       = T100TOKEN_ERROR;
                m_token->err        = T100ERROR_CHAR;
                return T100FALSE;
            }

            if(T100BYTE_ONE != m_item.type){
                m_token->type       = T100TOKEN_ERROR;
                m_token->err        = T100ERROR_CHAR;
                T100AssemblyError::error(T100AssemblyHint::file_hint(m_file.to_std_string(), T100CHARSCAN_CHAR_CODING_ERROR));
                return T100FALSE;
            }

            source.BYTE     = m_item.data;

            target.BYTE0.BIT5       = source.BIT0;
            target.BYTE0.BIT6       = source.BIT1;
            target.BYTE0.BIT7       = source.BIT2;

            target.BYTE1.BIT0       = source.BIT3;
            target.BYTE1.BIT1       = source.BIT4;
            target.BYTE1.BIT2       = source.BIT5;

            m_token->data       = target.WORD;
            m_token->row        = m_row;
            m_token->bytes.push_back(m_item.data);
            m_token->type       = classify();
            result              = T100TRUE;

            break;
        }
    case T100BYTE_THREE:
        {
            T100BYTE_BITS       source;
            T100WORD_BITS       target;

            source.BYTE     = m_item.data;

            target.BYTE0.BIT0       = source.BIT0;
            target.BYTE0.BIT1       = source.BIT1;
            target.BYTE0.BIT2       = source.BIT2;
            target.BYTE0.BIT3       = source.BIT3;

            m_token->bytes.push_back(m_item.data);

            if(!read()){
                m_token->type       = T100TOKEN_ERROR;
                m_token->err        = T100ERROR_CHAR;
                return T100FALSE;
            }
            if(T100BYTE_ONE != m_item.type){
                m_token->type       = T100TOKEN_ERROR;
                m_token->err        = T100ERROR_CHAR;
                T100AssemblyError::error(T100AssemblyHint::file_hint(m_file.to_std_string(), T100CHARSCAN_CHAR_CODING_ERROR));
                return T100FALSE;
            }

            source.BYTE     = m_item.data;

            target.BYTE0.BIT4       = source.BIT0;
            target.BYTE0.BIT5       = source.BIT1;
            target.BYTE0.BIT6       = source.BIT2;
            target.BYTE0.BIT7       = source.BIT3;

            target.BYTE1.BIT0       = source.BIT4;
            target.BYTE1.BIT1       = source.BIT5;

            m_token->bytes.push_back(m_item.data);

            if(!read()){
                m_token->type       = T100TOKEN_ERROR;
                m_token->err        = T100ERROR_CHAR;
                return T100FALSE;
            }
            if(T100BYTE_ONE != m_item.type){
                m_token->type       = T100TOKEN_ERROR;
                m_token->err        = T100ERROR_CHAR;
                T100AssemblyError::error(T100AssemblyHint::file_hint(m_file.to_std_string(), T100CHARSCAN_CHAR_CODING_ERROR));
                return T100FALSE;
            }

            source.BYTE     = m_item.data;

            target.BYTE1.BIT2       = source.BIT0;
            target.BYTE1.BIT3       = source.BIT1;
            target.BYTE1.BIT4       = source.BIT2;
            target.BYTE1.BIT5       = source.BIT3;

            target.BYTE1.BIT6       = source.BIT4;
            target.BYTE1.BIT7       = source.BIT5;

            m_token->data       = target.WORD;
            m_token->row        = m_row;
            m_token->bytes.push_back(m_item.data);
            m_token->type       = classify();
            result              = T100TRUE;

            break;
        }
    case T100BYTE_FOUR:
        {
            T100BYTE_BITS       source;
            T100WORD_BITS       target;

            source.BYTE     = m_item.data;

            target.BYTE0.BIT0       = source.BIT0;
            target.BYTE0.BIT1       = source.BIT1;
            target.BYTE0.BIT2       = source.BIT2;

            m_token->bytes.push_back(m_item.data);

            if(!read()){
                m_token->type       = T100TOKEN_ERROR;
                m_token->err        = T100ERROR_CHAR;
                return T100FALSE;
            }
            if(T100BYTE_ONE != m_item.type){
                m_token->type       = T100TOKEN_ERROR;
                m_token->err        = T100ERROR_CHAR;
                T100AssemblyError::error(T100AssemblyHint::file_hint(m_file.to_std_string(), T100CHARSCAN_CHAR_CODING_ERROR));
                return T100FALSE;
            }

            source.BYTE     = m_item.data;

            target.BYTE0.BIT3       = source.BIT0;
            target.BYTE0.BIT4       = source.BIT1;
            target.BYTE0.BIT5       = source.BIT2;
            target.BYTE0.BIT6       = source.BIT3;

            target.BYTE0.BIT7       = source.BIT4;
            target.BYTE1.BIT0       = source.BIT5;

            m_token->bytes.push_back(m_item.data);

            if(!read()){
                m_token->type       = T100TOKEN_ERROR;
                m_token->err        = T100ERROR_CHAR;
                return T100FALSE;
            }
            if(T100BYTE_ONE != m_item.type){
                m_token->type       = T100TOKEN_ERROR;
                m_token->err        = T100ERROR_CHAR;
                T100AssemblyError::error(T100AssemblyHint::file_hint(m_file.to_std_string(), T100CHARSCAN_CHAR_CODING_ERROR));
                return T100FALSE;
            }

            source.BYTE     = m_item.data;

            target.BYTE1.BIT1       = source.BIT0;
            target.BYTE1.BIT2       = source.BIT1;
            target.BYTE1.BIT3       = source.BIT2;
            target.BYTE1.BIT4       = source.BIT3;

            target.BYTE1.BIT5       = source.BIT4;
            target.BYTE1.BIT6       = source.BIT5;

            m_token->bytes.push_back(m_item.data);

            if(!read()){
                m_token->type       = T100TOKEN_ERROR;
                m_token->err        = T100ERROR_CHAR;
                return T100FALSE;
            }
            if(T100BYTE_ONE != m_item.type){
                m_token->type       = T100TOKEN_ERROR;
                m_token->err        = T100ERROR_CHAR;
                T100AssemblyError::error(T100AssemblyHint::file_hint(m_file.to_std_string(), T100CHARSCAN_CHAR_CODING_ERROR));
                return T100FALSE;
            }

            source.BYTE     = m_item.data;

            target.BYTE1.BIT7       = source.BIT0;
            target.BYTE2.BIT0       = source.BIT1;
            target.BYTE2.BIT1       = source.BIT2;
            target.BYTE2.BIT2       = source.BIT3;

            target.BYTE2.BIT3       = source.BIT4;
            target.BYTE2.BIT4       = source.BIT5;

            m_token->data       = target.WORD;
            m_token->row        = m_row;
            m_token->bytes.push_back(m_item.data);
            m_token->type       = classify();
            result              = T100TRUE;
            break;
        }
    case T100BYTE_FIVE:
        {
            m_token->type   = T100TOKEN_ERROR;
            m_token->err    = T100ERROR_CHAR;
            result          = T100FALSE;
            T100AssemblyError::error(T100AssemblyHint::file_hint(m_file.to_std_string(), T100CHARSCAN_CHAR_CODING_ERROR));
            break;
        }
    case T100BYTE_SIX:
        {
            m_token->type   = T100TOKEN_ERROR;
            m_token->err    = T100ERROR_CHAR;
            result          = T100FALSE;
            T100AssemblyError::error(T100AssemblyHint::file_hint(m_file.to_std_string(), T100CHARSCAN_CHAR_CODING_ERROR));
            break;
        }
    case T100BYTE_SEVEN:
        {
            m_token->type   = T100TOKEN_ERROR;
            m_token->err    = T100ERROR_CHAR;
            result          = T100FALSE;
            T100AssemblyError::error(T100AssemblyHint::file_hint(m_file.to_std_string(), T100CHARSCAN_CHAR_CODING_ERROR));
            break;
        }
    case T100TOKEN_EOF:
        {
            m_token->type   = T100TOKEN_EOF;
            m_token->eof    = m_item.eof;
            result          = T100TRUE;
            break;
        }
    };

    m_token->row    = m_row;

    return result;
}

T100BOOL T100CharScan::read()
{
    if(m_scan->next(m_item)){
        return T100TRUE;
    }else{

    }

    return T100FALSE;
}

T100BOOL T100CharScan::next(IToken &token)
{
    m_token = (T100CharToken*)&token;
    clear();

    return run();
}

T100BOOL T100CharScan::run()
{
    m_token->row    = m_row;

    if(!append()){
        return T100FALSE;
    }

    T100AssemblyLog::info(T100LOG_CHAR, T100AssemblyHint::char_hint(getToken(), T100CHARSCAN_CHAR_READ_SUCCESS));

    return T100TRUE;
}

T100TOKEN_TYPE T100CharScan::classify()
{
    T100TOKEN_TYPE      result      = T100TOKEN_NONE;
    T100WORD            data;

    data    = m_token->data;

    switch(data){
    case T100ASCII_LF:
        {
            m_row++;
            result = T100TOKEN_BR;
            m_token->data = ' ';
        }
        break;
    case T100ASCII_CR:
        {
            result = T100TOKEN_BR;
            m_token->data = ' ';
        }
        break;
    case T100ASCII_TAB:
    case T100ASCII_SPACE:
        {
            result = T100TOKEN_SPACE;
            m_token->data = ' ';
        }
        break;
    case T100ASCII_EXCLAMATION:
        {
            result = T100CHAR_EXCLAMATION;
        }
        break;
    case T100ASCII_DOUBLE_QUOTES:
        {
            result = T100CHAR_DOUBLE_QUOTES;
        }
        break;
    case T100ASCII_POUND:
        {
            result = T100CHAR_POUND;
        }
        break;
    case T100ASCII_DOLLAR:
        {
            result = T100CHAR_DOLLAR;
        }
        break;
    case T100ASCII_PERCENT:
        {
            result = T100CHAR_PERCENT;
        }
        break;
    case T100ASCII_AND:
        {
            result = T100CHAR_AND;
        }
        break;
    case T100ASCII_OPEN_SINGLE_QUOTES:
        {
            result = T100CHAR_OPEN_SINGLE_QUOTES;
        }
        break;
    case T100ASCII_CLOSED_SINGLE_QUOTES:
        {
            result = T100CHAR_CLOSED_SINGLE_QUOTES;
        }
        break;
    case T100ASCII_OPEN_PARENS:
        {
            result = T100CHAR_OPEN_PARENS;
        }
        break;
    case T100ASCII_CLOSED_PARENS:
        {
            result = T100CHAR_CLOSED_PARENS;
        }
        break;
    case T100ASCII_ASTERISK:
        {
            result = T100CHAR_ASTERISK;
        }
        break;
    case T100ASCII_PLUS:
        {
            result = T100CHAR_PLUS;
        }
        break;
    case T100ASCII_COMMA:
        {
            result = T100CHAR_COMMA;
        }
        break;
    case T100ASCII_MINUS:
        {
            result = T100CHAR_MINUS;
        }
        break;
    case T100ASCII_DOT:
        {
            result = T100CHAR_DOT;
        }
        break;
    case T100ASCII_SLASH:
        {
            result = T100CHAR_SLASH;
        }
        break;
    case T100ASCII_COLON:
        {
            result = T100CHAR_COLON;
        }
        break;
    case T100ASCII_SEMICOLON:
        {
            result = T100CHAR_SEMICOLON;
        }
        break;
    case T100ASCII_LESSTHAN:
        {
            result = T100CHAR_LESSTHAN;
        }
        break;
    case T100ASCII_EQUAL:
        {
            result = T100CHAR_EQUAL;
        }
        break;
    case T100ASCII_GREATERTHAN:
        {
            result = T100CHAR_GREATERTHAN;
        }
        break;
    case T100ASCII_QUESTION:
        {
            result = T100CHAR_QUESTION;
        }
        break;
    case T100ASCII_EMAIL:
        {
            result = T100CHAR_EMAIL;
        }
        break;
    case T100ASCII_OPEN_BRACKETS:
        {
            result = T100CHAR_OPEN_BRACKETS;
        }
        break;
    case T100ASCII_CLOSED_BRACKETS:
        {
            result = T100CHAR_CLOSED_BRACKETS;
        }
        break;
    case T100ASCII_BACKSLASH:
        {
            result = T100CHAR_BACKSLASH;
        }
        break;
    case T100ASCII_CARET:
        {
            result = T100CHAR_CARET;
        }
        break;
    case T100ASCII_UNDERLINE:
        {
            result = T100CHAR_UNDERLINE;
        }
        break;
    case T100ASCII_OPEN_BRACE:
        {
            result = T100CHAR_OPEN_BRACE;
        }
        break;
    case T100ASCII_CLOSED_BRACE:
        {
            result = T100CHAR_CLOSED_BRACE;
        }
        break;
    case T100ASCII_VERTICALBAR:
        {
            result = T100CHAR_VERTICALBAR;
        }
        break;
    case T100ASCII_TILDE:
        {
            result = T100CHAR_TILDE;
        }
        break;
    default:
        if(data >= T100ASCII_ZERO && data <= T100ASCII_NINE){
            result = T100CHAR_DIGIT;
        }else if(data >= T100ASCII_UPPER_A && data <= T100ASCII_UPPER_Z){
            result = T100CHAR_UPPER;
        }else if(data >= T100ASCII_LOWER_A && data <= T100ASCII_LOWER_Z){
            result = T100CHAR_LOWER;
        }else{
            result = T100CHAR_UNICODE;
        }
        break;
    }

    T100AssemblyLog::info(T100LOG_CHAR, T100AssemblyHint::char_hint(getToken(), T100CHARSCAN_CHAR_CLASSIFY_FINISHED));
    return result;
}

