#include "link/T1003DLight.h"

#include "link/T100Instance.h"

T1003DLight::T1003DLight() :
    T1003DObject()
{
    //ctor
}

T1003DLight::~T1003DLight()
{
    //dtor
}

T100VOID T1003DLight::SetPosition(T100FLOAT x, T100FLOAT y, T100FLOAT z)
{
    m_position  = {x, y, z};
    if(m_instancePtr){
        m_instancePtr->SetPosition(m_position);
    }
}

T100VOID T1003DLight::SetPosition(T100Vector3f& value)
{
    m_position  = value;
    if(m_instancePtr){
        m_instancePtr->SetPosition(m_position);
    }
}

T100VOID T1003DLight::SetRotation(T100FLOAT x, T100FLOAT y, T100FLOAT z)
{
    m_rotation  = {x, y, z};
    if(m_instancePtr){
        m_instancePtr->SetRotation(m_rotation);
    }
}

T100VOID T1003DLight::SetRotation(T100Vector3f& value)
{
    m_rotation  = value;
    if(m_instancePtr){
        m_instancePtr->SetRotation(m_rotation);
    }
}
