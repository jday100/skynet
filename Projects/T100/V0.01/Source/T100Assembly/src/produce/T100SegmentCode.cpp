#include "T100SegmentCode.h"

T100SegmentCode::T100SegmentCode()
{
    //ctor
}

T100SegmentCode::~T100SegmentCode()
{
    //dtor
}

T100BOOL T100SegmentCode::setValue(T100WORD value)
{
    m_mem[m_offset] = value;

    return T100TRUE;
}

T100VOID T100SegmentCode::next()
{
    m_offset++;
    m_mem.resize(m_offset + 1);
}

T100BOOL T100SegmentCode::addVariableCall(T100VARIABLE_CALL* call)
{
    m_variable_call.push_back(call);

    return T100TRUE;
}

T100BOOL T100SegmentCode::setLabel(T100String name, T100WORD offset)
{
    m_label_hash[name] = offset;

    return T100TRUE;
}

T100BOOL T100SegmentCode::getLabel(T100String name, T100WORD& offset)
{
    T100BOOL            result          = T100TRUE;
    T100LABELOFFSET_HASH::iterator      it;

    it = m_label_hash.find(name);

    if(it == m_label_hash.end()){
        result = T100FALSE;
    }else{
        offset  = it->second;
    }

    return result;
}

T100BOOL T100SegmentCode::addLabelCall(T100LABEL_CALL* call)
{
    m_label_call.push_back(call);

    return T100TRUE;
}

T100BOOL T100SegmentCode::setProcedure(T100String name, T100WORD offset)
{
    m_procedure_hash[name] = offset;

    return T100TRUE;
}

T100BOOL T100SegmentCode::getProcedure(T100String name, T100WORD& offset)
{
    T100BOOL            result          = T100TRUE;
    T100PROCEDUREOFFSET_HASH::iterator  it;

    it = m_procedure_hash.find(name);

    if(it == m_procedure_hash.end()){
        result = T100FALSE;
    }else{
        offset  = it->second;
    }

    return result;
}

T100BOOL T100SegmentCode::addProcedureCall(T100PROCEDURE_CALL* call)
{
    m_procedure_call.push_back(call);

    return T100TRUE;
}
