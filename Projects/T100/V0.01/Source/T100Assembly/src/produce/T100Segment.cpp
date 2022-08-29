#include "T100Segment.h"

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

    m_mem.resize(m_offset + 1);
    m_mem[m_offset] = value;

    m_offset++;

    return T100TRUE;
}

T100BOOL T100Segment::setString(T100WORD& offset, T100String str)
{
    T100WORD        size;
    T100WORD        length;
    T100WORD*       data            = T100NULL;

    length      = str.to_string().raw_length();
    size        = m_offset + length;

    if(0 != m_length && size > m_length){
        return T100FALSE;
    }

    data    = str.to_string().raw_data();

    if(!data){
        return T100FALSE;
    }

    m_mem.resize(size);
    offset = m_offset;

    for(int i=0;i<length;i++){
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
    m_offset = size;

    return T100TRUE;
}

T100VOID T100Segment::setName(T100String name)
{
    m_name = name;
}

T100String T100Segment::getName()
{
    return m_name;
}

T100WORD T100Segment::getLocation()
{
    return m_location;
}

T100WORD T100Segment::getLength()
{
    return m_length;
}
