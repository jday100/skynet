#include "T100Buffer.h"

T100Buffer::T100Buffer()
{
    //ctor
}

T100Buffer::~T100Buffer()
{
    //dtor
}

T100BOOL T100Buffer::empty()
{
    if(0 == m_length){
        return T100TRUE;
    }
    return T100FALSE;
}

T100VOID T100Buffer::setLength(INT32 length)
{
    m_length    = length;
}

T100WCHAR* T100Buffer::data()
{
    return m_buffer;
}

INT32 T100Buffer::length()
{
    return m_length;
}

INT32 T100Buffer::size()
{
    return m_size;
}

T100BOOL T100Buffer::next(T100WCHAR& letter)
{
    if(m_index >= m_length){
        return T100FALSE;
    }else{
        letter  = m_buffer[m_index++];
        return T100TRUE;
    }
    return T100FALSE;
}
