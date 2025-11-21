#include "T100DX12Light.h"

T100DX12Light::T100DX12Light()
{
    //ctor
}

T100DX12Light::~T100DX12Light()
{
    //dtor
}

T100VOID T100DX12Light::SetPosition(T100FLOAT x, T100FLOAT y, T100FLOAT z)
{
    m_position  = {x, y, z};
}

T100VOID T100DX12Light::SetPosition(T100Vector3 value)
{
    m_position  = value;
}

T100Vector3 T100DX12Light::GetPosition()
{
    return m_position;
}

T100VOID T100DX12Light::SetRotation(T100FLOAT x, T100FLOAT y, T100FLOAT z)
{
    m_rotation  = {x, y, z};
}

T100VOID T100DX12Light::SetRotation(T100Vector3 value)
{
    m_rotation  = value;
}

T100Vector3 T100DX12Light::GetRotation()
{
    return m_rotation;
}
