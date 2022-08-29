#include "T100String.h"

#include "T100Unicode.h"


T100String::T100String()
{
    //ctor
    m_raw_string.resize(2);
}

T100String::~T100String()
{
    //dtor
}

T100String::T100String(T100STDSTRING str)
    :m_std_string(str)
{
    m_string = T100Unicode::to_utf32(str);
    m_raw_string.resize(2);
    plus(*this, m_string);
}

T100String::T100String(T100STDSTRING32 str)
    :m_string(str)
{
    m_flag_stdstring    = T100TRUE;
    m_raw_string.resize(2);
    plus(*this, m_string);
}

T100BOOL T100String::empty()
{
    if(m_std_string.empty() && m_string.empty()){
        return T100TRUE;
    }

    return T100FALSE;
}

T100WORD T100String::getLength()
{
    return m_string.size();
}

T100WORD T100String::getRawLength()
{
    return m_raw_string.size();
}

T100WORD T100String::getByteLength()
{
    return m_raw_string.size() * 4;
}

T100WORD* T100String::getRawData()
{
    return (T100WORD*)(m_raw_string.data());
}

T100BYTE* T100String::getByteData()
{
    return (T100BYTE*)(m_raw_string.data());
}

const T100CHAR T100String::operator[](T100WORD index)const
{
    T100CHAR    result;

    result = m_string[index];

    return result;
}

const T100String T100String::operator+(const T100String& str)
{
    T100BOOL    result      = T100FALSE;
    T100String  target;

    target = *this;

    target.m_string         = this->m_string + str.m_string;
    target.m_std_string     = this->m_std_string + str.m_std_string;

    result = target.plus(target, str.m_raw_string);
    if(!result){
        target.clear();
        return target;
    }
    return target;
}

const T100String& T100String::operator+=(const T100String& str)
{
    T100BOOL    result      = T100FALSE;
    T100String  target;

    target = *this;

    target.m_string         = this->m_string + str.m_string;
    target.m_std_string     = this->m_std_string + str.m_std_string;

    result = target.plus(target, str.m_raw_string);
    if(!result){
        return *this;
    }

    *this = target;

    return *this;
}

const T100String T100String::operator=(const T100String& str)
{
    this->m_flag_stdstring  = str.m_flag_stdstring;
    this->m_flag_string     = str.m_flag_string;

    this->m_string          = str.m_string;
    this->m_std_string      = str.m_std_string;
    this->m_raw_string      = str.m_raw_string;

    return *this;
}

T100BOOL T100String::operator==(const T100String& str)const
{
    return m_string == str.m_string;
}

T100BOOL T100String::operator!=(const T100String& str)const
{
    return m_string != str.m_string;
}

T100BOOL T100String::plus(T100String& obj, T100STDSTRING32& str)
{
    T100WORD    length;
    T100WORD    rawlength;
    T100WORD    size;
    T100WORD    current;

    size        = str.size();
    length      = obj.m_raw_string[0] + size;
    rawlength   = length + 2;
    current     = obj.m_raw_string.size() - 1;

    obj.m_raw_string.resize(rawlength);

    for(int i=0;i<size;i++){
        obj.m_raw_string[current++] = str[i];
    }

    obj.m_raw_string[0] = length;
    obj.m_raw_string[rawlength - 1] = 0;

    return verify(obj);
}

T100BOOL T100String::plus(T100String& obj, const T100STRING_CHAR_VECTOR& str)
{
    T100WORD        strlength;
    T100WORD        rawlength;
    T100WORD        length;
    T100WORD        size;
    T100WORD        source;
    T100WORD        target;

    strlength   = obj.m_raw_string.size() + str.size() - 4;
    length      = str.size();
    size        = length - 2;
    rawlength   = obj.m_raw_string.size() + size;
    source      = 1;
    target      = obj.m_raw_string.size() - 1;

    obj.m_raw_string.resize(rawlength);

    for(int i=0;i<size;i++){
        obj.m_raw_string[target++] = str[source++];
    }

    obj.m_raw_string[0] = strlength;
    obj.m_raw_string[rawlength - 1] = 0;

    return verify(obj);
}

T100BOOL T100String::append(T100CHAR ch)
{
    T100STDSTRING32     str;
    T100STDSTRING       result;

    str             += ch;

    result          = T100Unicode::to_utf8(str);

    m_std_string    += result;
    m_string        += ch;

    if(!plus(*this, str)){
        return T100FALSE;
    }

    return T100TRUE;
}

T100VOID T100String::clear()
{
    m_string.clear();
    m_std_string.clear();

    m_raw_string.resize(2);
    m_raw_string[0] = 0;
    m_raw_string[1] = 0;
}

T100BOOL T100String::verify(T100String& obj)
{
    T100WORD    length;

    length = obj.m_string.size();

    if(obj.m_string.size() != obj.m_std_string.size()){
        //return T100FALSE;
    }

    if((length + 2) != obj.m_raw_string.size()){
        return T100FALSE;
    }

    if(length != obj.m_raw_string[0]){
        return T100FALSE;
    }

    if(0 != obj.m_raw_string[length + 1]){
        return T100FALSE;
    }

    return T100TRUE;
}

T100STDSTRING T100String::to_std_string()
{
    if(m_flag_stdstring){
        m_std_string = T100Unicode::to_utf8(m_string);
        m_flag_stdstring = T100FALSE;
    }
    return m_std_string;
}

T100STDSTRING32 T100String::to_std_string32()
{
    return m_string;
}
