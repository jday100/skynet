#include "link/T1003DObject.h"

#include "link/T100Instance.h"

T1003DObject::T1003DObject()
{
    //ctor
}

T1003DObject::~T1003DObject()
{
    //dtor
}

T100VOID T1003DObject::SetPosition(T100FLOAT x, T100FLOAT y, T100FLOAT z)
{
    m_position  = {x, y, z};
    if(m_instancePtr){
        m_instancePtr->SetPosition(m_position);
    }
}

T100VOID T1003DObject::SetPosition(T100Vector3f& value)
{
    m_position  = value;
    if(m_instancePtr){
        m_instancePtr->SetPosition(m_position);
    }
}

T100Vector3f& T1003DObject::GetPosition()
{
    return m_position;
}

T100VOID T1003DObject::SetRotation(T100FLOAT x, T100FLOAT y, T100FLOAT z)
{
    m_rotation  = {x, y, z};
    if(m_instancePtr){
        m_instancePtr->SetRotation(m_rotation);
    }
}

T100VOID T1003DObject::SetRotation(T100Vector3f& value)
{
    m_rotation  = value;
    if(m_instancePtr){
        m_instancePtr->SetRotation(m_rotation);
    }
}

T100Vector3f& T1003DObject::GetRotation()
{
    return m_rotation;
}

T100VOID T1003DObject::SetInstancePtr(T100Instance* instance)
{
    m_instancePtr   = instance;
}

T100Instance* T1003DObject::GetInstancePtr()
{
    return m_instancePtr;
}
