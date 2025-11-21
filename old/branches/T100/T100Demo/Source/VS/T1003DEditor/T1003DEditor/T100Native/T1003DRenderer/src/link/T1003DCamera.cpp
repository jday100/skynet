#include "link/T1003DCamera.h"

#include "link/T100Instance.h"

T1003DCamera::T1003DCamera(T1003D_COORDINATE_SYSTEM_TYPE type) :
    T1003DObject(),
    m_type(type),
    m_lookat(0.0f, 0.0f, 1.0f),
    m_up(0.0f, 1.0f, 0.0f),
    m_fov(0.8f),
    m_aspectRatio(0.0f),
    m_nearPlane(1.0f),
    m_farPlane(100.0f)
{
    //ctor
}

T1003DCamera::~T1003DCamera()
{
    //dtor
}

T100VOID T1003DCamera::Reset()
{
    m_lookat    = {0.0f, 0.0f, 1.0f};
    m_up        = {0.0f, 1.0f, 0.0f};
    m_fov       = 0.8f;
    m_nearPlane = 1.0f;
    m_farPlane  = 100.0f;

    m_position  = {0.0f, 0.0f, 0.0f};
    m_rotation  = {0.0f, 0.0f, 0.0f};

    if(m_instancePtr){
        m_instancePtr->Reset();
    }
}

T1003D_COORDINATE_SYSTEM_TYPE T1003DCamera::GetType()
{
    return m_type;
}

T100VOID T1003DCamera::SetLookAt(T100FLOAT x, T100FLOAT y, T100FLOAT z)
{
    m_lookat    = {x, y, z};
}

T100VOID T1003DCamera::SetLookAt(T100Vector3f& value)
{
    m_lookat    = value;
}

T100Vector3f& T1003DCamera::GetLookAt()
{
    return m_lookat;
}

T100VOID T1003DCamera::SetUp(T100FLOAT x, T100FLOAT y, T100FLOAT z)
{
    m_up    = {x, y, z};
}

T100VOID T1003DCamera::SetUp(T100Vector3f& value)
{
    m_up    = value;
}

T100Vector3f& T1003DCamera::GetUp()
{
    return m_up;
}

T100VOID T1003DCamera::SetFov(T100FLOAT value)
{
    m_fov   = value;
}

T100FLOAT T1003DCamera::GetFov()
{
    return m_fov;
}

T100VOID T1003DCamera::SetAspectRatio(T100FLOAT value)
{
    m_aspectRatio   = value;
}

T100FLOAT T1003DCamera::GetAspectRatio()
{
    return m_aspectRatio;
}

T100VOID T1003DCamera::SetNearPlane(T100FLOAT value)
{
    m_nearPlane     = value;
}

T100FLOAT T1003DCamera::GetNearPlane()
{
    return m_nearPlane;
}

T100VOID T1003DCamera::SetFarPlane(T100FLOAT value)
{
    m_farPlane      = value;
}

T100FLOAT T1003DCamera::GetFarPlane()
{
    return m_farPlane;
}

T100VOID T1003DCamera::GetViewMatrix(T100Matrix4f& matrix)
{
    m_instancePtr->GetViewMatrix(matrix);
}

T100VOID T1003DCamera::GetProjectionMatrix(T100Matrix4f& matrix)
{
    m_instancePtr->GetProjectionMatrix(matrix);
}

T100VOID T1003DCamera::GetTranslation(T100Matrix4f& matrix)
{
    m_instancePtr->GetTranslation(matrix);
}

T100VOID T1003DCamera::Unproject(const T100Vector3f& source, T100FLOAT x, T100FLOAT y,
    T100UINT width, T100UINT height, T100FLOAT minz, T100FLOAT maxz, const T100Matrix4f& project,
    const T100Matrix4f& view, const T100Matrix4f& world, T100Vector3f& target)
{
    m_instancePtr->Unproject(source, x, y, width, height, minz, maxz, project, view, world, target);
}

T100VOID T1003DCamera::SetPosition(T100FLOAT x, T100FLOAT y, T100FLOAT z)
{
    m_position  = {x, y, z};
    if(m_instancePtr){
        m_instancePtr->SetPosition(m_position);
    }
}

T100VOID T1003DCamera::SetPosition(T100Vector3f& value)
{
    m_position  = value;
    if(m_instancePtr){
        m_instancePtr->SetPosition(m_position);
    }
}

T100VOID T1003DCamera::SetRotation(T100FLOAT x, T100FLOAT y, T100FLOAT z)
{
    m_rotation  = {x, y, z};
    if(m_instancePtr){
        m_instancePtr->SetRotation(m_rotation);
    }
}

T100VOID T1003DCamera::SetRotation(T100Vector3f& value)
{
    m_rotation  = value;
    if(m_instancePtr){
        m_instancePtr->SetRotation(m_rotation);
    }
}

T100VOID T1003DCamera::SetInstancePtr(T100CameraInstance* instance)
{
    m_instancePtr   = instance;
}

T100CameraInstance* T1003DCamera::GetInstancePtr()
{
    return m_instancePtr;
}
