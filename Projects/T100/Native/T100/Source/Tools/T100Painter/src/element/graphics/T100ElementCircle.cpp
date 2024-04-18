#include "T100ElementCircle.h"

#include "T100ElementCommon.h"
#include "T100BivectorTools.h"

T100ElementCircle::T100ElementCircle()
    :T100ElementBase()
{
    //ctor
    create();
}

T100ElementCircle::~T100ElementCircle()
{
    //dtor
    destroy();
}

T100VOID T100ElementCircle::create()
{
    m_type      = T100ELEMENT_GRAPHICS_CIRCLE;

    m_origin_x  = 0;
    m_origin_y  = 0;

    m_radius    = 1;
}

T100VOID T100ElementCircle::destroy()
{

}

T100VOID T100ElementCircle::SetStartingPoint(T100INT x, T100INT y)
{
    T100ElementBase::SetStartingPoint(x, y);
    m_origin_x  = x;
    m_origin_y  = y;
}

T100VOID T100ElementCircle::SetTerminalPoint(T100INT x, T100INT y)
{
    T100ElementBase::SetTerminalPoint(x, y);
    m_target_x  = x;
    m_target_y  = y;

    T100Bivector        a(m_origin_x, m_origin_y);
    T100Bivector        b(m_target_x, m_target_y);

    m_radius    = std::round(T100BivectorTools::distance(a, b));
}

T100BOOL T100ElementCircle::Draw(wxDC& dc)
{
    dc.DrawCircle(m_origin_x, m_origin_y, m_radius);
    return T100TRUE;
}
