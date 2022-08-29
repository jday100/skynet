#include "T100String32.h"

T100String32::T100String32()
{
    //ctor
    clear();
}

T100String32::T100String32(T100CHAR32* str)
{
    T100WORD        size;
    T100STRING32    result(str);

    size = result.size();

    m_string32.resize(1);

    m_string32  += result;
    m_string32  += U'\0';

    m_string32[0] = size;
}

T100String32::~T100String32()
{
    //dtor
}

T100BOOL T100String32::empty()
{
    if(2 >= m_string32.size()){
        return T100TRUE;
    }

    return T100FALSE;
}

T100VOID T100String32::clear()
{
    m_string32.resize(2);
    m_string32[0] = 0;
    m_string32[1] = 0;
}

T100WORD T100String32::length()
{
    if(2 >= m_string32.size()){
        return 0;
    }

    return m_string32.size() - 2;
}

T100WORD T100String32::raw_length()
{
    return m_string32.size();
}

T100WORD T100String32::byte_length()
{
    return 4 * m_string32.size();
}

T100CHAR32* T100String32::data()
{
    T100CHAR32*     result      = T100NULL;

    result = &m_string32[1];

    return result;
}

T100WORD* T100String32::raw_data()
{
    T100WORD*       result      = T100NULL;

    result = (T100WORD*)m_string32.data();

    return result;
}

T100BYTE* T100String32::byte_data()
{
    T100BYTE*       result      = T100NULL;

    result = (T100BYTE*)m_string32.data();

    return result;
}

T100BOOL T100String32::operator==(const T100String32& str)
{
    return m_string32 == str.m_string32;
}

T100BOOL T100String32::operator!=(const T100String32& str)
{
    return m_string32 != str.m_string32;
}

T100String32 T100String32::operator+=(const T100CHAR32 ch)
{
    T100WORD    size;
    T100WORD    length;

    size    = m_string32.size();

    if(2 <= size){
        length  = size - 1;
        size++;
    }else{
        size    = 3;
        length  = 1;
    }

    m_string32.resize(size);
    m_string32[length]      = ch;
    m_string32[0]           = length;
    m_string32[length+1]    = 0;

    return *this;
}

T100String32 T100String32::operator+(const T100CHAR32 ch)
{
    T100String32    result;

    result.m_string32   = m_string32;

    result += ch;

    return result;
}

T100String32 T100String32::operator+=(const T100String32& str)
{
    T100WORD        strlength;
    T100WORD        rawlength;
    T100WORD        length;
    T100WORD        size;
    T100WORD        source;
    T100WORD        target;

    //test
    size    = m_string32.size();
    size    = str.m_string32.size();

    strlength   = m_string32.size() + str.m_string32.size() - 4;
    length      = str.m_string32.size();
    size        = length - 2;
    rawlength   = m_string32.size() + size;
    source      = 1;
    target      = m_string32.size() - 1;

    m_string32.resize(rawlength);

    for(int i=0;i<size;i++){
        m_string32[target++] = str.m_string32[source++];
    }

    m_string32[0] = strlength;
    m_string32[rawlength - 1] = 0;

    return *this;
}

T100String32 T100String32::operator+(const T100String32& str)
{
    T100String32    result;

    result.m_string32 = m_string32;

    result += str;

    return result;
}

T100BOOL operator==(const T100CHAR32* source, const T100String32& target)
{
    T100String32    result(const_cast<T100CHAR32*>(source));

    return result == target;
}

T100BOOL operator!=(const T100CHAR32* source, const T100String32& target)
{
    T100String32    result(const_cast<T100CHAR32*>(source));

    return result != target;
}

T100String32 operator+(const T100CHAR32* source, const T100String32& target)
{
    T100String32    result(const_cast<T100CHAR32*>(source));

    result += target;

    return result;
}
