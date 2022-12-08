#include "T100Segment.h"

namespace T100Assembly{

T100Segment::T100Segment()
{
    //ctor
}

T100Segment::~T100Segment()
{
    //dtor
}

T100WORD T100Segment::size()
{
    return m_mem.size();
}

T100WORD_VECTOR& T100Segment::getMem()
{
    return m_mem;
}

T100WORD T100Segment::getOffset()
{
    return m_offset;
}

T100BOOL T100Segment::setWord(T100WORD& offset, T100WORD value)
{
    if(0 != m_length && m_offset >= m_length){
        return T100FALSE;
    }

    T100WORD        temp;

    temp = m_offset + 1;
    m_mem.resize(temp);
    m_mem[m_offset] = value;

    offset      = m_offset + m_location;
    m_offset    = temp;

    return T100TRUE;
}

T100BOOL T100Segment::setString(T100WORD& offset, T100STRING str)
{
    T100WORD        size;
    T100WORD        length;
    T100WORD*       data            = T100NULL;

    length      = str.to_string32().raw_length();
    size        = m_offset + length;

    if(0 != m_length && size > m_length){
        return T100FALSE;
    }

    data    = str.to_string32().raw_data();
    if(!data){
        return T100FALSE;
    }

    m_mem.resize(size);
    offset = m_offset;

    for(int i=0; i<length; i++){
        size = data[i];
        m_mem[m_offset] = data[i];
        m_offset++;
    }

    m_mem[offset]       = length - 2;
    m_mem[m_offset - 1] = 0;

    return T100TRUE;
}

T100BOOL T100Segment::setArray(T100WORD& offset, T100WORD length)
{
    T100WORD        size;

    size    = m_offset + length;

    if(0 != m_length && size > m_length){
        return T100FALSE;
    }

    m_mem.resize(size);
    offset      = m_offset + m_location;
    m_offset    = size;

    return T100TRUE;
}

T100BOOL T100Segment::setArrayInteger(T100WORD& offset, T100WORD length, T100WORD value)
{
    T100WORD        size;
    T100WORD        index;

    index   = m_offset;

    size    = m_offset + length;

    if(0 != m_length && size > m_length){
        return T100FALSE;
    }

    m_mem.resize(size);
    offset      = m_offset + m_location;
    m_offset    = size;

    for(int i=0;i<length;i++){
        m_mem[index++] = value;
    }

    return T100TRUE;
}

T100BOOL T100Segment::setArrayInteger(T100WORD& offset, T100WORD length, T100WORD_VECTOR& value)
{
    T100WORD        size;
    T100WORD        index;

    index   = m_offset;
    size    = value.size();

    if(length < value.size()){
        return T100FALSE;
    }

    size    = m_offset + length;

    if(0 != m_length && size > m_length){
        return T100FALSE;
    }

    m_mem.resize(size);
    offset      = m_offset + m_location;
    m_offset    = size;

    for(T100WORD item : value){
        m_mem[index++] = item;
    }

    return T100TRUE;
}

T100BOOL T100Segment::setArrayFloat(T100WORD& offset, T100WORD length, T100FLOAT_VECTOR& value)
{
    return T100FALSE;
}

T100BOOL T100Segment::setArrayString(T100WORD& offset, T100WORD length, T100STRING_VECTOR& value)
{
    return T100FALSE;
}

T100VOID T100Segment::setName(T100STRING name)
{
    m_name = name;
}

T100STRING T100Segment::getName()
{
    return m_name;
}

T100WORD T100Segment::getLocation()
{
    return m_location;
}

T100WORD T100Segment::getLength()
{
    if(0 == m_length){
        return m_mem.size();
    }
    return m_length;
}

}
