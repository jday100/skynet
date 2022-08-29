#include "T100SegmentData.h"

T100SegmentData::T100SegmentData()
{
    //ctor
}

T100SegmentData::~T100SegmentData()
{
    //dtor
}

T100BOOL T100SegmentData::setValue(T100WORD value)
{
    m_mem[m_offset] = value;

    return T100TRUE;
}

T100VOID T100SegmentData::next()
{
    m_offset++;
    m_mem.resize(m_offset + 1);
}

T100BOOL T100SegmentData::setVariable(T100String name, T100WORD offset)
{
    m_variable_hash[name] = offset;

    return T100TRUE;
}

T100BOOL T100SegmentData::getVariable(T100String name, T100WORD& offset)
{
    T100BOOL            result          = T100TRUE;
    T100VARIABLEOFFSET_HASH::iterator   it;

    it = m_variable_hash.find(name);

    if(it == m_variable_hash.end()){
        result = T100FALSE;
    }else{
        offset = it->second;
    }

    return result;
}
