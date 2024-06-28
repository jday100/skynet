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

T100VOID T100Render::SetView(T100ViewBase* view)
{
    m_view  = view;
}

T100ViewBase* T100Render::GetView()
{
    return m_view;
}

T100VOID T100Render::SetOrigin(T100FLOAT x, T100FLOAT y, T100FLOAT z)
{
    m_render->SetOrigin(x, y, z);
}

T100VOID T100Render::project(T100INT x, T100INT y, T100FLOAT& a, T100FLOAT& b, T100FLOAT& c)
{

}

T100VOID T100Render::Draw(T100VOID* data)
{
    m_render->Draw();
    m_view->Draw(data);
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

T100VOID T100Render::Move(T100FLOAT x, T100FLOAT y, T100FLOAT z)
{
    m_render->Move(x, y, z);
}

T100VOID T100Render::Rotate(T100FLOAT x, T100FLOAT y, T100FLOAT z)
{
    m_render->Rotate(x, y, z);
}
