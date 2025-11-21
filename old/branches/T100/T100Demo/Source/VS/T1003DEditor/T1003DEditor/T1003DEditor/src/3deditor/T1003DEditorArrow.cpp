#include "3deditor/T1003DEditorArrow.h"

#include "data/T100GameScene.h"

T1003DEditorArrow::T1003DEditorArrow()
{
    //ctor
    init();
}

T1003DEditorArrow::~T1003DEditorArrow()
{
    //dtor
    uninit();
}

T100VOID T1003DEditorArrow::init()
{
    m_line      = T100NEW T100Line();
    m_arrow1    = T100NEW T100Line();
    m_arrow2    = T100NEW T100Line();
    m_arrow3    = T100NEW T100Line();

    m_line->SetLength(0.1);
    m_line->SetRenderType(T1003D_RENDER_SCREEN);

    m_arrow1->SetRenderType(T1003D_RENDER_SCREEN);
    m_arrow2->SetRenderType(T1003D_RENDER_SCREEN);
    m_arrow3->SetRenderType(T1003D_RENDER_SCREEN);
}

T100VOID T1003DEditorArrow::uninit()
{
    T100SAFE_DELETE m_line;
    T100SAFE_DELETE m_arrow1;
    T100SAFE_DELETE m_arrow2;
    T100SAFE_DELETE m_arrow3;
}

T100VOID T1003DEditorArrow::Load(T100GameScene* scene)
{
    scene->AppendStaticMesh(m_line);
    scene->AppendStaticMesh(m_arrow1);
    scene->AppendStaticMesh(m_arrow2);
    scene->AppendStaticMesh(m_arrow3);
}

T100VOID T1003DEditorArrow::SetPosition(T100FLOAT x, T100FLOAT y, T100FLOAT z)
{
    m_line->SetPosition(x, y, z);

}

T100VOID T1003DEditorArrow::SetPosition(T100Vector3f& value)
{
    m_line->SetPosition(value);
}

T100Vector3f& T1003DEditorArrow::GetPosition()
{
    return m_line->GetPosition();
}

T100VOID T1003DEditorArrow::SetRotation(T100FLOAT x, T100FLOAT y, T100FLOAT z)
{
    m_line->SetRotation(x, y, z);
}

T100VOID T1003DEditorArrow::SetRotation(T100Vector3f& value)
{
    m_line->SetRotation(value);
}

T100Vector3f& T1003DEditorArrow::GetRotation()
{
    return m_line->GetRotation();
}

T100VOID T1003DEditorArrow::SetScaling(T100FLOAT x, T100FLOAT y, T100FLOAT z)
{
    m_line->SetScaling(x, y, z);
}

T100VOID T1003DEditorArrow::SetScaling(T100Vector3f& value)
{
    m_line->SetScaling(value);
}

T100Vector3f& T1003DEditorArrow::GetScaling()
{
    return m_line->GetScaling();
}

T100VOID T1003DEditorArrow::SetColour(T100UINT8 red, T100UINT8 green, T100UINT8 blue, T100UINT8 alpha)
{
    m_line->SetColour(red, green, blue, alpha);
    m_arrow1->SetColour(red, green, blue, alpha);
    m_arrow2->SetColour(red, green, blue, alpha);
    m_arrow3->SetColour(red, green, blue, alpha);
}

T100Vector4u& T1003DEditorArrow::GetColour()
{
    return m_line->GetColour();
}

T100VOID T1003DEditorArrow::SetVisible(T100BOOL flag)
{
    m_line->SetVisible(flag);
}

T100BOOL T1003DEditorArrow::IsVisible()
{
    return m_line->IsVisible();
}

T100VOID T1003DEditorArrow::SetLength(T100FLOAT value)
{
    m_line->SetLength(value);
}

T100FLOAT T1003DEditorArrow::GetLength()
{
    return m_line->GetLength();
}
