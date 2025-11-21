#include "T100Camera.h"

#include "renderer/data/T100DX12Camera.h"

T100Camera::T100Camera()
{
    //ctor
}

T100Camera::~T100Camera()
{
    //dtor
}

T100VOID T100Camera::SetPosition(T100FLOAT x, T100FLOAT y, T100FLOAT z)
{
    m_position  = {x, y, z};
    if(m_camera){
        m_camera->SetPosition(m_position);
    }
}

T100VOID T100Camera::SetPosition(T100Vector3 value)
{
    m_position  = value;
    if(m_camera){
        m_camera->SetPosition(m_position);
    }
}

T100Vector3 T100Camera::GetPosition()
{
    return m_position;
}

T100VOID T100Camera::SetRotation(T100FLOAT x, T100FLOAT y, T100FLOAT z)
{
    m_rotation  = {x, y, z};
    if(m_camera){
        m_camera->SetRotation(m_rotation);
    }
}

T100VOID T100Camera::SetRotation(T100Vector3 value)
{
    m_rotation  = value;
    if(m_camera){
        m_camera->SetRotation(m_rotation);
    }
}

T100Vector3 T100Camera::GetRotation()
{
    return m_rotation;
}

T100VOID T100Camera::SetScaling(T100FLOAT x, T100FLOAT y, T100FLOAT z)
{
    m_scaling   = {x, y, z};
}

T100VOID T100Camera::SetScaling(T100Vector3 value)
{
    m_scaling   = value;
}

T100Vector3 T100Camera::GetScaling()
{
    return m_scaling;
}
