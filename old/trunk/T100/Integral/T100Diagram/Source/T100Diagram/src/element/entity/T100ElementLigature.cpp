#include "T100ElementLigature.h"

T100ElementLigature::T100ElementLigature() :
    T100ElementBase()
{
    //ctor
    m_type      = T100ELEMENT_LIGATURE;
}

T100ElementLigature::~T100ElementLigature()
{
    //dtor
}

T100VOID T100ElementLigature::SetStart(T100ElementBase* element)
{
    m_start         = element;
    m_startIndex    = element->GetIndex();
}

T100ElementBase* T100ElementLigature::GetStart()
{
    return m_start;
}

T100VOID T100ElementLigature::SetEnd(T100ElementBase* element)
{
    m_end           = element;
    m_endIndex      = element->GetIndex();
}

T100ElementBase* T100ElementLigature::GetEnd()
{
    return m_end;
}

T100VOID T100ElementLigature::SetStartIndex(T100UINT value)
{
    m_startIndex    = value;
}

T100UINT T100ElementLigature::GetStartIndex()
{
    return m_startIndex;
}

T100VOID T100ElementLigature::SetEndIndex(T100UINT value)
{
    m_endIndex      = value;
}

T100UINT T100ElementLigature::GetEndIndex()
{
    return m_endIndex;
}

T100BOOL T100ElementLigature::Draw(wxDC& dc)
{
    if(m_start && m_end){

    }else{
        return T100FALSE;
    }

    T100UINT    sx, sy;
    T100UINT    ex, ey;

    m_start->Cross(m_end->GetCentroidX(), m_end->GetCentroidY(), sx, sy);
    m_end->Cross(m_start->GetCentroidX(), m_start->GetCentroidY(), ex, ey);

    dc.DrawLine(sx, sy, ex, ey);

    return T100TRUE;
}

T100BOOL T100ElementLigature::Hit(T100INT, T100INT)
{
    return T100FALSE;
}


T100BOOL T100ElementLigature::Edit(wxWindow* parent)
{
    return T100FALSE;
}

T100BOOL T100ElementLigature::Cross(T100UINT, T100UINT, T100UINT&, T100UINT&)
{

}

T100VOID T100ElementLigature::Resize(wxDC&)
{

}
