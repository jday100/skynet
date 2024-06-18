#include "T100Render.h"

#include "T100SoftRender.h"

T100Render::T100Render()
{
    //ctor
    TurnOn();
}

T100Render::~T100Render()
{
    //dtor
    TurnOff();
}

T100VOID T100Render::TurnOn()
{
    m_render    = T100NEW T100SoftRender();
}

T100VOID T100Render::TurnOff()
{
    T100SAFE_DELETE(m_render)
}

T100VOID T100Render::Draw()
{
    m_render->Draw();
}

T100VOID T100Render::SetSize(T100INT width, T100INT height)
{
    m_render->SetSize(width, height);
}

T100BYTE* T100Render::GetData()
{
    return m_render->GetData();
}

T100INT T100Render::GetWidth()
{
    return m_render->GetWidth();
}

T100INT T100Render::GetHeight()
{
    return m_render->GetHeight();
}

T100ENTITY_VECTOR& T100Render::GetEntities()
{
    return m_render->GetEntities();
}
