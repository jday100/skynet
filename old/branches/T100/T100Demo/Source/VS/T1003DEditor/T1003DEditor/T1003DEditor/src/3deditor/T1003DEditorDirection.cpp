#include "3deditor/T1003DEditorDirection.h"

T1003DEditorDirection::T1003DEditorDirection() :
    m_arrowX(), m_arrowY(), m_arrowZ()
{
    //ctor
}

T1003DEditorDirection::~T1003DEditorDirection()
{
    //dtor
}

T100VOID T1003DEditorDirection::Load(T100GameScene* scene)
{
    m_arrowY.SetRotation(0, 0, 90);
    m_arrowZ.SetRotation(0, 90, 0);

    m_arrowX.Load(scene);
    m_arrowY.Load(scene);
    m_arrowZ.Load(scene);
}

T100VOID T1003DEditorDirection::SetPosition(T100FLOAT x, T100FLOAT y, T100FLOAT z)
{
    m_arrowX.SetPosition(x, y, z);
    m_arrowY.SetPosition(x, y, z);
    m_arrowZ.SetPosition(x, y, z);
}

T100VOID T1003DEditorDirection::SetPosition(T100Vector3f& value)
{
    m_arrowX.SetPosition(value);
    m_arrowY.SetPosition(value);
    m_arrowZ.SetPosition(value);
}

T100Vector3f& T1003DEditorDirection::GetPosition()
{
    return m_arrowX.GetPosition();
}

T100VOID T1003DEditorDirection::SetRotation(T100FLOAT x, T100FLOAT y, T100FLOAT z)
{

}

T100VOID T1003DEditorDirection::SetRotation(T100Vector3f& value)
{

}

T100Vector3f& T1003DEditorDirection::GetRotation()
{
    return m_arrowX.GetRotation();
}

T100VOID T1003DEditorDirection::SetScaling(T100FLOAT x, T100FLOAT y, T100FLOAT z)
{

}

T100VOID T1003DEditorDirection::SetScaling(T100Vector3f& value)
{

}

T100Vector3f& T1003DEditorDirection::GetScaling()
{
    return m_arrowX.GetScaling();
}

T100VOID T1003DEditorDirection::SetColour(T100UINT8 red, T100UINT8 green, T100UINT8 blue, T100UINT8 alpha)
{
    m_arrowX.SetColour(red, green, blue, alpha);
    m_arrowY.SetColour(red, green, blue, alpha);
    m_arrowZ.SetColour(red, green, blue, alpha);
}

T100Vector4u& T1003DEditorDirection::GetColour()
{
    return m_arrowX.GetColour();
}

T100VOID T1003DEditorDirection::SetVisible(T100BOOL flag)
{

}

T100BOOL T1003DEditorDirection::IsVisible()
{

}

T100VOID T1003DEditorDirection::SetLength(T100FLOAT value)
{

}

T100FLOAT T1003DEditorDirection::GetLength()
{

}
