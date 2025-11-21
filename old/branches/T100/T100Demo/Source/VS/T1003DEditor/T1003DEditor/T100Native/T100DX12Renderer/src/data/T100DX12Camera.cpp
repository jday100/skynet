#include "data/T100DX12Camera.h"

#include "link/T1003DCamera.h"
#include "math/T100DX12MathTools.h"

T100DX12Camera::T100DX12Camera() :
    T100CameraInstance()
{
    //ctor
}

T100DX12Camera::~T100DX12Camera()
{
    //dtor
}

T100VOID T100DX12Camera::SetStudioPtr(T100DX12Studio* studio)
{
    m_studioPtr = studio;
}

T100DX12Studio* T100DX12Camera::GetStudioPtr()
{
    return m_studioPtr;
}

T100VOID T100DX12Camera::Setup(T1003DCamera* camera)
{
    SetSource(camera);

    m_type          = camera->GetType();
    m_lookat        = camera->GetLookAt();
    m_up            = camera->GetUp();

    m_fov           = camera->GetFov();
    m_aspectRatio   = camera->GetAspectRatio();
    m_nearPlane     = camera->GetNearPlane();
    m_farPlane      = camera->GetFarPlane();

    m_position      = camera->GetPosition();
    m_rotation      = camera->GetRotation();

    XMVECTOR        position;
    XMVECTOR        lookat;
    XMVECTOR        up;

    XMMATRIX        view;
    XMMATRIX        rotationx;
    XMMATRIX        rotationy;
    XMMATRIX        rotationz;

    position    = XMLoadFloat3((const XMFLOAT3*)&m_position.FLOAT3);
    lookat      = XMLoadFloat3((const XMFLOAT3*)&m_lookat.FLOAT3);
    up          = XMLoadFloat3((const XMFLOAT3*)&m_up.FLOAT3);

    if(m_type == T1003D_COORDINATE_SYSTEM_LEFT_HAND){
        view            = XMMatrixLookToLH(position, lookat, up);
        m_projection    = XMMatrixPerspectiveFovLH(m_fov, m_aspectRatio, m_nearPlane, m_farPlane);
    }else if(m_type == T1003D_COORDINATE_SYSTEM_RIGHT_HAND){
        view            = XMMatrixLookToRH(position, lookat, up);
        m_projection    = XMMatrixPerspectiveFovRH(m_fov, m_aspectRatio, m_nearPlane, m_farPlane);
    }

    rotationx   = XMMatrixRotationX(m_rotation.X);
    rotationy   = XMMatrixRotationY(m_rotation.Y);
    rotationz   = XMMatrixRotationZ(m_rotation.Z);

    m_view      = rotationx * rotationy * rotationz * view;
}

T100VOID T100DX12Camera::GetViewMatrix(T100Matrix4f& matrix)
{
    Convert(m_view, matrix);
}

T100VOID T100DX12Camera::GetProjectionMatrix(T100Matrix4f& matrix)
{
    Convert(m_projection, matrix);
}

T100VOID T100DX12Camera::GetViewMatrix(XMMATRIX& matrix)
{
    matrix  = m_view;
}

T100VOID T100DX12Camera::GetProjectionMatrix(XMMATRIX& matrix)
{
    matrix  = m_projection;
}

T100VOID T100DX12Camera::GetTranslation(T100Matrix4f& matrix)
{
    XMMATRIX    world;

    world   = XMMatrixTranslation(0, 0, 0);

    Convert(world, matrix);
}

T100VOID T100DX12Camera::Unproject(const T100Vector3f& source, T100FLOAT x, T100FLOAT y,
    T100UINT width, T100UINT height, T100FLOAT minz, T100FLOAT maxz, const T100Matrix4f& project,
    const T100Matrix4f& view, const T100Matrix4f& world, T100Vector3f& target)
{
    XMVECTOR    value;
    XMVECTOR    result;

    XMMATRIX    xmproject;
    XMMATRIX    xmview;
    XMMATRIX    xmworld;

    value       = XMLoadFloat3((const XMFLOAT3*)&source.FLOAT3);

    Convert(project, xmproject);
    Convert(view, xmview);
    Convert(world, xmworld);

    result  = XMVector3Unproject(value, x, y, width, height, minz, maxz, xmproject, xmview, xmworld);

    Convert(result, target);
}

T100VOID T100DX12Camera::SetPosition(T100FLOAT x, T100FLOAT y, T100FLOAT z)
{
    m_position  = {x, y, z};
    XMVECTOR        position;
    XMVECTOR        lookat;
    XMVECTOR        up;

    position    = XMLoadFloat3((const XMFLOAT3*)&m_position.FLOAT3);
    lookat      = XMLoadFloat3((const XMFLOAT3*)&m_lookat.FLOAT3);
    up          = XMLoadFloat3((const XMFLOAT3*)&m_up.FLOAT3);

    if(m_type == T1003D_COORDINATE_SYSTEM_LEFT_HAND){
        m_view          = XMMatrixLookToLH(position, lookat, up);
    }else if(m_type == T1003D_COORDINATE_SYSTEM_RIGHT_HAND){
        m_view          = XMMatrixLookToRH(position, lookat, up);
    }
}

T100VOID T100DX12Camera::SetPosition(T100Vector3f& value)
{
    m_position  = value;

    XMVECTOR        position;
    XMVECTOR        lookat;
    XMVECTOR        up;

    position    = XMLoadFloat3((const XMFLOAT3*)&m_position.FLOAT3);
    lookat      = XMLoadFloat3((const XMFLOAT3*)&m_lookat.FLOAT3);
    up          = XMLoadFloat3((const XMFLOAT3*)&m_up.FLOAT3);

    if(m_type == T1003D_COORDINATE_SYSTEM_LEFT_HAND){
        m_view          = XMMatrixLookToLH(position, lookat, up);
    }else if(m_type == T1003D_COORDINATE_SYSTEM_RIGHT_HAND){
        m_view          = XMMatrixLookToRH(position, lookat, up);
    }
}

T100VOID T100DX12Camera::SetRotation(T100FLOAT x, T100FLOAT y, T100FLOAT z)
{
    T100Vector3f    rotation  = {x, y, z};

    AngleToRadian(rotation, m_rotation);
    BuildView();
}

T100VOID T100DX12Camera::SetRotation(T100Vector3f& value)
{
    AngleToRadian(value, m_rotation);
    BuildView();
}

T100VOID T100DX12Camera::BuildView()
{
    XMVECTOR        position;
    XMVECTOR        lookat;
    XMVECTOR        up;

    XMMATRIX        view;
    XMMATRIX        rotationx;
    XMMATRIX        rotationy;
    XMMATRIX        rotationz;

    XMMATRIX        value;

    position    = XMLoadFloat3((const XMFLOAT3*)&m_position.FLOAT3);
    lookat      = XMLoadFloat3((const XMFLOAT3*)&m_lookat.FLOAT3);
    up          = XMLoadFloat3((const XMFLOAT3*)&m_up.FLOAT3);

    if(m_type == T1003D_COORDINATE_SYSTEM_LEFT_HAND){
        view            = XMMatrixLookToLH(position, lookat, up);
    }else if(m_type == T1003D_COORDINATE_SYSTEM_RIGHT_HAND){
        view            = XMMatrixLookToRH(position, lookat, up);
    }

    rotationx   = XMMatrixRotationX(m_rotation.X);
    rotationy   = XMMatrixRotationY(m_rotation.Y);
    rotationz   = XMMatrixRotationZ(m_rotation.Z);

    value   = rotationx * rotationy * rotationz * view;

    m_view  = value;
}

T100VOID T100DX12Camera::Clear()
{

}

T100VOID T100DX12Camera::Reset()
{
    Setup(m_source);
}
