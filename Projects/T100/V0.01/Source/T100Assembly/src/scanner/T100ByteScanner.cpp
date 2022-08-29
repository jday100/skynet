#include "T100ByteScanner.h"

#include "T100Unicode.h"


T100ByteScanner::T100ByteScanner()
{
    //ctor
}

T100ByteScanner::~T100ByteScanner()
{
    //dtor
}

T100BOOL T100ByteScanner::open(T100WSTRING file)
{
    T100STDSTRING       name;

    if(m_ifs){
        return T100FALSE;
    }

    name = T100Unicode::to_string8(file);

    m_ifs = T100NEW std::ifstream(name.c_str(), std::ios::in | std::ios::binary);
    if(m_ifs->is_open()){
        m_file = file;
        return T100TRUE;
    }else{
        T100SAFE_DELETE(m_ifs);
    }

    return T100FALSE;
}

T100BOOL T100ByteScanner::close()
{
    if(m_ifs){
        m_ifs->close();
        T100SAFE_DELETE(m_ifs);
        return T100TRUE;
    }
    return T100FALSE;
}

T100BOOL T100ByteScanner::next(T100Token& token)
{
    m_token = (T100ByteToken*)&token;
    m_token->clear();

    return run();
}

T100BOOL T100ByteScanner::run()
{
    if(!read()){
        return T100FALSE;
    }

    switch(m_token->type){
    case T100TOKEN_EOF:
        {
        }
        break;
    case T100TOKEN_ERROR:
        {
        }
        break;
    default:
        getToken()->type        = classify(getToken()->value);
        //T100AssemblyLog::info(T100LOG_BYTE, T100AssemblyHint::byte_hint(getToken(), T100BYTESCAN_BYTE_READ_SUCCESS));
    };

    return T100TRUE;
}

T100BOOL T100ByteScanner::read()
{
    if(m_index > m_length){
        m_token->type   = T100TOKEN_ERROR;
        m_token->err    = T100ERROR_BYTE;
        return T100FALSE;
    }else if(m_index == m_length){
        if(m_ifs->eof()){
            m_token->eof    = T100TRUE;
            m_token->type   = T100TOKEN_EOF;
            m_index++;
            return T100TRUE;
        }else{
            m_length = m_ifs->read(m_buffer, 1024).gcount();
            m_index = 0;
        }
    }

    if(m_length > 0){
        m_token->value = m_buffer[m_index];
        m_index++;
        return T100TRUE;
    }else if(0 == m_length){
        if(m_ifs->eof()){
            m_token->eof    = T100TRUE;
            m_token->type   = T100TOKEN_EOF;
            m_index++;
            return T100TRUE;
        }
    }

    return T100FALSE;
}

T100ByteToken* T100ByteScanner::getToken()
{
    return m_token;
}

T100TOKEN_TYPE T100ByteScanner::classify(T100BYTE byte)
{
    T100TOKEN_TYPE      result = T100TOKEN_NONE;

    T100BYTE_BITS       bits;

    bits.BYTE           = byte;

    if(bits.BIT7 == T100FALSE){
        result  = T100BYTE_ASCII;
    }else if(bits.BIT6 == T100FALSE){
        result  = T100BYTE_ONE;
    }else if(bits.BIT5 == T100FALSE){
        result  = T100BYTE_TWO;
    }else if(bits.BIT4 == T100FALSE){
        result  = T100BYTE_THREE;
    }else if(bits.BIT3 == T100FALSE){
        result  = T100BYTE_FOUR;
    }else if(bits.BIT2 == T100FALSE){
        result  = T100BYTE_FIVE;
    }else if(bits.BIT1 == T100FALSE){
        result  = T100BYTE_SIX;
    }else{
        result  = T100BYTE_SEVEN;
    }

    //T100AssemblyLog::info(T100LOG_BYTE, T100AssemblyHint::byte_hint(getToken(), T100BYTESCAN_BYTE_CLASSIFY_FINISHED));
    return result;
}
