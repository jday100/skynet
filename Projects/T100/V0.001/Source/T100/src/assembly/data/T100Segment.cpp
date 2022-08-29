#include "T100Segment.h"

#include <assert.h>


T100Segment::T100Segment()
    :m_variables(), m_mem()
{
    //ctor
}

T100Segment::~T100Segment()
{
    //dtor
}

T100WORD_VECTOR& T100Segment::getMem()
{
    return m_mem;
}

T100WORD T100Segment::getOffset()
{
    return m_offset;
}

T100WORD T100Segment::getLocation()
{
    return m_location;
}

T100WORD T100Segment::getLength()
{
    return m_mem.size();
}

T100VOID T100Segment::setName(T100String name)
{
    m_name = name;
}

T100String T100Segment::getName()
{
    return m_name;
}

T100BOOL T100Segment::setWord(T100WORD& offset, T100WORD value)
{
    if(m_length != 0 && m_offset >= m_length){
        T100AssemblyError::error(T100AssemblyHint::segment_hint(this, T100BUILD_SEGMENT_LENGTH_LIMIT_ERROR));
        return T100FALSE;
    }

    m_mem.resize(m_offset + 1);
    m_mem[m_offset] = value;

    offset = m_offset + m_location;     //test
    m_offset++;

    return T100TRUE;
}

T100BOOL T100Segment::setString(T100WORD& offset, T100String str)
{
    T100WORD    size;
    T100WORD    length;
    T100WORD*   data        = T100NULL;

    length      = str.getRawLength();
    size        = m_offset + length;

    if(m_length != 0 && size > m_length){
        T100AssemblyError::error(T100AssemblyHint::segment_hint(this, T100BUILD_SEGMENT_LENGTH_LIMIT_ERROR));
        return T100FALSE;
    }

    data    = str.getRawData();
    if(!data){
        T100AssemblyError::error(T100AssemblyHint::segment_hint(this, T100BUILD_SEGMENT_ERROR));
        return T100FALSE;
    }

    m_mem.resize(size);
    offset = m_offset;

    for(int i=0;i<length;i++){
        //test
        T100WORD temp = data[i];
        m_mem[m_offset] = data[i];
        m_offset++;
    }

    //test
    m_mem[offset] = length - 2;
    m_mem[m_offset - 1] = 0;

    offset = offset + m_location;   //test

    return true;
}

T100BOOL T100Segment::setArray(T100WORD& offset, T100WORD length)
{
    T100WORD    size;

    size        = m_offset + length;

    if(m_length != 0 && size > m_length){
        T100AssemblyError::error(T100AssemblyHint::segment_hint(this, T100BUILD_SEGMENT_LENGTH_LIMIT_ERROR));
        return T100FALSE;
    }

    m_mem.resize(size);
    offset      = m_offset + m_location;     //test
    m_offset    = size;

    return T100TRUE;
}

T100BOOL T100Segment::setVariable(T100String name, T100WORD offset)
{
    m_variables[name] = offset;
    return T100TRUE;
}

T100BOOL T100Segment::getVariable(T100String name, T100WORD& offset)
{
    //assert(m_variables.size() != 0);

    T100VARIABLEOFFSET_HASH::iterator it;

    it = m_variables.find(name);

    if(it == m_variables.end()){
        return T100FALSE;
    }else{
        offset = it->second;
    }
    return T100TRUE;
}
