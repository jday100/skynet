#include "T100SegmentCode.h"

T100SegmentCode::T100SegmentCode()
{
    //ctor
    create();
}

T100SegmentCode::~T100SegmentCode()
{
    //dtor
}

T100VOID T100SegmentCode::create()
{
    m_mem.resize(m_offset + 1);
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

T100BOOL T100SegmentCode::setLabel(T100String name, T100WORD offset)
{
    m_labels[name] = offset;

    return T100TRUE;
}

T100BOOL T100SegmentCode::getLabel(T100String name, T100WORD& offset)
{
    T100BOOL    result      = T100FALSE;
    T100LABELOFFSET_HASH::iterator      it;

    it = m_labels.find(name);

    if(it == m_labels.end()){

    }else{
        offset = it->second;
        result = T100TRUE;
    }

    return result;
}

T100BOOL T100SegmentCode::addLabelCall(T100LABEL_CALL* c)
{
    m_label_call.push_back(c);
    return T100TRUE;
}

T100BOOL T100SegmentCode::addVariableCall(T100VARIABLE_CALL* c)
{
    m_variable_call.push_back(c);
    return T100TRUE;
}

T100BOOL T100SegmentCode::setProcedure(T100String name, T100WORD offset)
{
    m_procedures[name] = offset;

    return T100TRUE;
}

T100BOOL T100SegmentCode::getProcedure(T100String name, T100WORD& offset)
{
    T100BOOL    result      = T100FALSE;
    T100PROCEDUREOFFSET_HASH::iterator      it;

    it = m_procedures.find(name);

    if(it == m_procedures.end()){

    }else{
        offset = it->second;
        result = T100TRUE;
    }

    return result;
}

T100BOOL T100SegmentCode::addProcedureCall(T100PROCEDURE_CALL* c)
{
    m_procedure_call.push_back(c);
    return T100TRUE;
}
