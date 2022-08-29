#include "T100ByteScan.h"


T100ByteScan::T100ByteScan()
{
    //ctor
}

T100ByteScan::~T100ByteScan()
{
    //dtor
}

T100BOOL T100ByteScan::open(T100String& file)
{
    m_file = file;

    if(m_ifs){
        T100AssemblyError::warn(T100AssemblyHint::file_hint(m_file.to_std_string(), T100BYTESCAN_FILE_OPEN_FAILURE));
        return T100FALSE;
    }

    m_ifs = T100NEW std::ifstream(file.to_std_string(), std::ios::in | std::ios::binary);

    if(m_ifs->is_open()){
        T100Log::info(T100AssemblyHint::file_hint(m_file.to_std_string(), T100BYTESCAN_FILE_OPEN_SUCCESS));
        return T100TRUE;
    }else{
        T100AssemblyError::fatal(T100AssemblyHint::file_hint(m_file.to_std_string(), T100BYTESCAN_FILE_OPEN_FAILURE));
    }

    return T100FALSE;
}

T100BOOL T100ByteScan::close()
{
    if(m_ifs){
        m_ifs->close();
        m_ifs = T100NULL;

        T100Log::info(T100AssemblyHint::file_hint(m_file.to_std_string(), T100BYTESCAN_FILE_CLOSE_SUCCESS));
        return T100TRUE;
    }else{
        T100AssemblyError::warn(T100AssemblyHint::file_hint(m_file.to_std_string(), T100BYTESCAN_FILE_CLOSE_FAILURE));
    }

    return T100FALSE;
}

T100ByteToken* T100ByteScan::getToken()
{
    return m_token;
}

T100BOOL T100ByteScan::read()
{
    if(m_offset > m_length){
        m_token->type   = T100TOKEN_ERROR;
        m_token->err    = T100ERROR_BYTE;
        return T100FALSE;
    }else if(m_offset == m_length){
        if(m_ifs->eof()){
            m_token->eof    = T100TRUE;
            m_token->type   = T100TOKEN_EOF;
            m_offset++;
            return T100TRUE;
        }else{
            m_length = m_ifs->read(m_buffer, 1024).gcount();
            m_offset = 0;
        }
    }

    if(m_length > 0){
        m_token->data = m_buffer[m_offset];
        m_offset++;
        return T100TRUE;
    }else if(0 == m_length){
        if(m_ifs->eof()){
            m_token->eof    = T100TRUE;
            m_token->type   = T100TOKEN_EOF;
            m_offset++;
            return T100TRUE;
        }
    }

    return T100FALSE;
}

T100BOOL T100ByteScan::next(IToken &token)
{
    m_token = (T100ByteToken*)&token;
    m_token->clear();

    return run();
}

T100BOOL T100ByteScan::run()
{
    if(!read()){
        T100AssemblyError::fatal(T100AssemblyHint::file_hint(m_file.to_std_string(), T100BYTESCAN_BYTE_READ_FAILURE));
        return T100FALSE;
    }

    switch(m_token->type){
    case T100TOKEN_EOF:
        {
            T100AssemblyLog::info(T100LOG_BYTE, T100AssemblyHint::byte_hint(getToken(), T100BYTESCAN_BYTE_READ_SUCCESS));
        }
        break;
    case T100TOKEN_ERROR:
        {
            T100AssemblyError::error(T100AssemblyHint::byte_hint(getToken(), T100BYTESCAN_BYTE_READ_FAILURE));
        }
        break;
    default:
        getToken()->type        = classify(getToken()->data);
        T100AssemblyLog::info(T100LOG_BYTE, T100AssemblyHint::byte_hint(getToken(), T100BYTESCAN_BYTE_READ_SUCCESS));
    };

    return T100TRUE;
}

T100TOKEN_TYPE T100ByteScan::classify(T100BYTE data)
{
    T100TOKEN_TYPE      result = T100TOKEN_NONE;

    T100BYTE_BITS       bits;

    bits.BYTE           = data;

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

    T100AssemblyLog::info(T100LOG_BYTE, T100AssemblyHint::byte_hint(getToken(), T100BYTESCAN_BYTE_CLASSIFY_FINISHED));
    return result;
}
