#include "T100ElementSingleTrack.h"

T100ElementSingleTrack::T100ElementSingleTrack() :
    T100ElementBase()
{
    //ctor
    m_type      = T100ELEMENT_SINGLE_TRACK;
}

T100ElementSingleTrack::~T100ElementSingleTrack()
{
    //dtor
}

T100VOID T100ElementSingleTrack::SetStart(T100ElementBase* element)
{
    m_start         = element;
    m_startIndex    = element->GetIndex();
}

T100ElementBase* T100ElementSingleTrack::GetStart()
{
    return m_start;
}

T100VOID T100ElementSingleTrack::SetEnd(T100ElementBase* element)
{
    m_end           = element;
    m_endIndex      = element->GetIndex();
}

T100ElementBase* T100ElementSingleTrack::GetEnd()
{
    return m_end;
}

T100VOID T100ElementSingleTrack::SetStartIndex(T100UINT value)
{
    m_startIndex    = value;
}

T100UINT T100ElementSingleTrack::GetStartIndex()
{
    return m_startIndex;
}

T100VOID T100ElementSingleTrack::SetEndIndex(T100UINT value)
{
    m_endIndex      = value;
}

T100UINT T100ElementSingleTrack::GetEndIndex()
{
    return m_endIndex;
}

T100BOOL T100ElementSingleTrack::Draw(wxDC& dc)
{
    if(m_start && m_end){

    }else{
        return T100FALSE;
    }

    T100UINT    sx, sy;
    T100UINT    ex, ey;

    m_start->Cross(m_end->GetCentroidX(), m_end->GetCentroidY(), sx, sy);
    m_end->Cross(m_start->GetCentroidX(), m_start->GetCentroidY(), ex, ey);

    T100UINT    a1, b1, a2, b2, a3, b3;

    Arrow(sx, sy, ex, ey, a1, b1, a2, b2, a3, b3);

    dc.DrawLine(a1, b1, ex, ey);
    dc.DrawLine(a2, b2, ex, ey);
    dc.DrawLine(a1, b1, a2, b2);

    dc.DrawLine(sx, sy, ex, ey);

    return T100TRUE;
}

T100BOOL T100ElementSingleTrack::Hit(T100INT, T100INT)
{
    return T100FALSE;
}


T100BOOL T100ElementSingleTrack::Edit(wxWindow* parent)
{
    return T100FALSE;
}

T100BOOL T100ElementSingleTrack::Cross(T100UINT, T100UINT, T100UINT&, T100UINT&)
{

}

T100VOID T100ElementSingleTrack::Resize(wxDC&)
{

}
