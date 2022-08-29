#include "T100Error.h"

T100BOOL        T100Error::err              = T100FALSE;
T100WORD        T100Error::m_fatal_count    = 0;
T100WORD        T100Error::m_error_count    = 0;
T100WORD        T100Error::m_warn_count     = 0;


T100Error::T100Error()
{
    //ctor
}

T100Error::~T100Error()
{
    //dtor
}

T100BOOL T100Error::fatal(T100STDSTRING msg)
{
    err = T100TRUE;
    m_fatal_count++;
    T100Log::fatal(msg);
    return T100TRUE;
}

T100BOOL T100Error::error(T100STDSTRING msg)
{
    err = T100TRUE;
    m_error_count++;
    T100Log::error(msg);
    return T100TRUE;
}

T100BOOL T100Error::warn(T100STDSTRING msg)
{
    err = T100TRUE;
    m_warn_count++;
    T100Log::warn(msg);
    return T100TRUE;
}
