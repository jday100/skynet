#include "T100FireServe.h"

T100FireServe::T100FireServe()
{
    //ctor
    //TurnOn();
}

T100FireServe::~T100FireServe()
{
    //dtor
    //TurnOff();
}

T100VOID T100FireServe::TurnOn()
{
    m_render    = T100NEW T100Render();
}

T100VOID T100FireServe::TurnOff()
{
    T100SAFE_DELETE(m_render)
}

T100VOID T100FireServe::SetRender(T100Render* render)
{
    m_render    = render;
}

T100Render* T100FireServe::GetRender()
{
    return m_render;
}
