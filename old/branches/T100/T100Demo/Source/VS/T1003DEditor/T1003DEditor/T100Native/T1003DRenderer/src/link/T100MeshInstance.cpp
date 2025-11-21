#include "link/T100MeshInstance.h"

T100MeshInstance::T100MeshInstance() :
    T100Instance()
{
    //ctor
}

T100MeshInstance::~T100MeshInstance()
{
    //dtor
}

/*
T100VOID T100MeshInstance::SetScaling(T100FLOAT x, T100FLOAT y, T100FLOAT z)
{
    m_scaling   = {x, y, z};
}

T100VOID T100MeshInstance::SetScaling(T100Vector3f& value)
{
    m_scaling   = value;
}
*/

T100Vector3f& T100MeshInstance::GetScaling()
{
    return m_scaling;
}

/*
T100VOID T100MeshInstance::SetVisible(T100BOOL flag)
{
    m_visible   = flag;
}
*/

T100BOOL T100MeshInstance::IsVisible()
{
    return m_visible;
}

T100VOID T100MeshInstance::SetAmount(T100UINT value)
{
    m_amount    = value;
}

T100UINT T100MeshInstance::GetAmount()
{
    return m_amount;
}
