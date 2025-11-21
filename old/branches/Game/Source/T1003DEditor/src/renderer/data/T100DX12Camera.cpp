#include "T100DX12Camera.h"

#undef NOMINMAX

#ifndef NOMINMAX

#ifndef max
#define max(a,b)            (((a) > (b)) ? (a) : (b))
#endif

#ifndef min
#define min(a,b)            (((a) < (b)) ? (a) : (b))
#endif

#endif  /* NOMINMAX */

T100DX12Camera::T100DX12Camera() :
    m_initialPosition(0, 0, 0),
    m_position(m_initialPosition),
    m_yaw(XM_PI),
    m_pitch(0.0f),
    m_lookDirection(0, 0, 1),
    m_upDirection(0, 1, 0),
    m_moveSpeed(20.0f),
    m_turnSpeed(XM_PIDIV2),
    m_keysPressed{}
{
    //ctor
}

T100DX12Camera::~T100DX12Camera()
{
    //dtor
}

void T100DX12Camera::Init(XMFLOAT3 position)
{
    m_initialPosition = position;
    Reset();

    UpdateView();
    UpdateProjection();
}

T100VOID T100DX12Camera::SetCoordinateSystemType(T100DX12_COORDINATE_SYSTEM_TYPE type)
{
    m_coordinateType    = type;
}

T100DX12_COORDINATE_SYSTEM_TYPE T100DX12Camera::GetCoordinateSystemType()
{
    return m_coordinateType;
}

T100VOID T100DX12Camera::SetProjectionType(T100DX12_PROJECTION_TYPE type)
{
    m_projectionType    = type;
}

T100DX12_PROJECTION_TYPE T100DX12Camera::GetProjectionType()
{
    return m_projectionType;
}

T100VOID T100DX12Camera::SetFov(T100FLOAT value)
{
    m_fov   = value;
}

T100FLOAT T100DX12Camera::GetFov()
{
    return m_fov;
}

T100VOID T100DX12Camera::SetAspectRatio(T100FLOAT value)
{
    m_aspectRatio   = value;
}

T100FLOAT T100DX12Camera::GetAspectRatio()
{
    return m_aspectRatio;
}

T100VOID T100DX12Camera::SetNearPlane(T100FLOAT value)
{
    m_nearPlane     = value;
}

T100FLOAT T100DX12Camera::GetNearPlane()
{
    return m_nearPlane;
}

T100VOID T100DX12Camera::SetFarPlane(T100FLOAT value)
{
    m_farPlane      = value;
}

T100FLOAT T100DX12Camera::GetFarPlane()
{
    return m_farPlane;
}

T100VOID T100DX12Camera::SetWidth(T100FLOAT value)
{
    m_width     = value;
}

T100FLOAT T100DX12Camera::GetWidth()
{
    return m_width;
}

T100VOID T100DX12Camera::SetHeight(T100FLOAT value)
{
    m_height    = value;
}

T100FLOAT T100DX12Camera::GetHeight()
{
    return m_height;
}

void T100DX12Camera::SetMoveSpeed(float unitsPerSecond)
{
    m_moveSpeed = unitsPerSecond;
}

void T100DX12Camera::SetTurnSpeed(float radiansPerSecond)
{
    m_turnSpeed = radiansPerSecond;
}

void T100DX12Camera::Reset()
{
    m_position = m_initialPosition;
    m_yaw = XM_PI;
    m_pitch = 0.0f;
    m_lookDirection = { 0, 0, 1 };
}

T100Vector3 T100DX12Camera::GetPosition()
{
    T100Vector3     result;

    result = {m_position.x, m_position.y, m_position.z};

    return result;
}

T100Vector3 T100DX12Camera::GetLookAt()
{
    T100Vector3     result;

    result = {m_lookDirection.x, m_lookDirection.y, m_lookDirection.z};

    return result;
}

T100Vector3 T100DX12Camera::GetUp()
{
    T100Vector3     result;

    result = {m_upDirection.x, m_upDirection.y, m_upDirection.z};

    return result;
}

T100VOID T100DX12Camera::UpdateView()
{
    switch(m_coordinateType){
    case T100DX12_COORDINATE_SYSTEM_LEFT_HAND:
        {
            m_view  = XMMatrixLookToLH(XMLoadFloat3(&m_position), XMLoadFloat3(&m_lookDirection), XMLoadFloat3(&m_upDirection));
        }
        break;
    case T100DX12_COORDINATE_SYSTEM_RIGHT_HAND:
        {
            m_view  = XMMatrixLookToRH(XMLoadFloat3(&m_position), XMLoadFloat3(&m_lookDirection), XMLoadFloat3(&m_upDirection));
        }
        break;
    }
}

T100VOID T100DX12Camera::UpdateProjection()
{
    switch(m_projectionType){
    case T100DX12_ORTHOGRAPHIC_PROJECTION:
        {
            switch(m_coordinateType){
            case T100DX12_COORDINATE_SYSTEM_LEFT_HAND:
                {
                    m_projection    = XMMatrixOrthographicLH(m_width, m_height, m_nearPlane, m_farPlane);
                }
                break;
            case T100DX12_COORDINATE_SYSTEM_RIGHT_HAND:
                {
                    m_projection    = XMMatrixOrthographicRH(m_width, m_height, m_nearPlane, m_farPlane);
                }
                break;
            }
        }
        break;
    case T100DX12_PERSPECTIVE_PROJECTION:
        {
            switch(m_coordinateType){
            case T100DX12_COORDINATE_SYSTEM_LEFT_HAND:
                {
                    m_projection    = XMMatrixPerspectiveFovLH(m_fov, m_aspectRatio, m_nearPlane, m_farPlane);
                }
                break;
            case T100DX12_COORDINATE_SYSTEM_RIGHT_HAND:
                {
                    m_projection    = XMMatrixPerspectiveFovRH(m_fov, m_aspectRatio, m_nearPlane, m_farPlane);
                }
                break;
            }
        }
        break;
    }
}

void T100DX12Camera::Update(float elapsedSeconds)
{
    XMFLOAT3 move(0, 0, 0);

    if (m_keysPressed.a)
        move.x -= 1.0f;
    if (m_keysPressed.d)
        move.x += 1.0f;
    if (m_keysPressed.w)
        move.z -= 1.0f;
    if (m_keysPressed.s)
        move.z += 1.0f;

    if (fabs(move.x) > 0.1f && fabs(move.z) > 0.1f)
    {
        XMVECTOR vector = XMVector3Normalize(XMLoadFloat3(&move));
        move.x = XMVectorGetX(vector);
        move.z = XMVectorGetZ(vector);
    }

    float moveInterval = m_moveSpeed * elapsedSeconds;
    float rotateInterval = m_turnSpeed * elapsedSeconds;

    if (m_keysPressed.left)
        m_yaw += rotateInterval;
    if (m_keysPressed.right)
        m_yaw -= rotateInterval;
    if (m_keysPressed.up)
        m_pitch += rotateInterval;
    if (m_keysPressed.down)
        m_pitch -= rotateInterval;

    m_pitch = min(m_pitch, XM_PIDIV4);
    m_pitch = max(-XM_PIDIV4, m_pitch);

    float x = move.x * -cosf(m_yaw) - move.z * sinf(m_yaw);
    float z = move.x * sinf(m_yaw) - move.z * cosf(m_yaw);
    m_position.x += x * moveInterval;
    m_position.z += z * moveInterval;

    float r = cosf(m_pitch);
    m_lookDirection.x = r * sinf(m_yaw);
    m_lookDirection.y = sinf(m_pitch);
    m_lookDirection.z = r * cosf(m_yaw);
}

XMMATRIX& T100DX12Camera::GetViewMatrix()
{
    return m_view;
}

XMMATRIX& T100DX12Camera::GetProjectionMatrix()
{
    return m_projection;
}

void T100DX12Camera::OnKeyDown(WPARAM key)
{
    switch (key)
    {
    case 'W':
        m_keysPressed.w = true;
        break;
    case 'A':
        m_keysPressed.a = true;
        break;
    case 'S':
        m_keysPressed.s = true;
        break;
    case 'D':
        m_keysPressed.d = true;
        break;
    case VK_LEFT:
        m_keysPressed.left = true;
        break;
    case VK_RIGHT:
        m_keysPressed.right = true;
        break;
    case VK_UP:
        m_keysPressed.up = true;
        break;
    case VK_DOWN:
        m_keysPressed.down = true;
        break;
    case VK_ESCAPE:
        Reset();
        break;
    }
}

void T100DX12Camera::OnKeyUp(WPARAM key)
{
    switch (key)
    {
    case 'W':
        m_keysPressed.w = false;
        break;
    case 'A':
        m_keysPressed.a = false;
        break;
    case 'S':
        m_keysPressed.s = false;
        break;
    case 'D':
        m_keysPressed.d = false;
        break;
    case VK_LEFT:
        m_keysPressed.left = false;
        break;
    case VK_RIGHT:
        m_keysPressed.right = false;
        break;
    case VK_UP:
        m_keysPressed.up = false;
        break;
    case VK_DOWN:
        m_keysPressed.down = false;
        break;
    }
}

void T100DX12Camera::GetScreenToViewRay(T100UINT screenX, T100UINT screenY, T100Vector3& origin, T100Vector3& direction)
{
    XMVECTOR    unkown;
    XMMATRIX    project;
    XMMATRIX    view;

    XMMATRIX    value;
    XMMATRIX    inverse;

    project     = GetProjectionMatrix();
    view        = GetViewMatrix();

    value       = project * view;

    inverse     = XMMatrixInverse(&unkown, value);

    T100FLOAT   nx  = (2.0f * screenX) - 1.0f;
    T100FLOAT   ny  = 1.0f - (2.0f * screenY);

    //XMVECTOR    nearPoint = XMLoadFloat(nx, ny, -1.0f);


    /*
    Matrix4 inverseVP = (getProjectionMatrix() * getViewMatrix(true)).inverse();

    Real nx = (2.0f * screenX) - 1.0f;
    Real ny = 1.0f - (2.0f * screenY);
    Vector3 nearPoint(nx, ny, -1.f);
    // Use midPoint rather than far point to avoid issues with infinite projection
    Vector3 midPoint (nx, ny,  0.0f);

    // Get ray origin and ray target on near plane in world space
    Vector3 rayOrigin, rayTarget;

    rayOrigin = inverseVP * nearPoint;
    rayTarget = inverseVP * midPoint;

    Vector3 rayDirection = rayTarget - rayOrigin;
    rayDirection.normalise();

    outRay->setOrigin(rayOrigin);
    outRay->setDirection(rayDirection);
    */
}

T100VOID T100DX12Camera::SetPosition(T100FLOAT x, T100FLOAT y, T100FLOAT z)
{
    m_position  = {x, y, z};
}

T100VOID T100DX12Camera::SetPosition(T100Vector3 value)
{
    memcpy(&m_position, &value.FLOAT3, sizeof(XMFLOAT3));
}

T100VOID T100DX12Camera::SetRotation(T100FLOAT x, T100FLOAT y, T100FLOAT z)
{
    m_rotation  = {x, y, z};
}

T100VOID T100DX12Camera::SetRotation(T100Vector3 value)
{
    m_rotation  = value;
}

T100Vector3 T100DX12Camera::GetRotation()
{
    return m_rotation;
}

T100VOID T100DX12Camera::SetScaling(T100FLOAT x, T100FLOAT y, T100FLOAT z)
{
    m_scaling   = {x, y, z};
}

T100VOID T100DX12Camera::SetScaling(T100Vector3 value)
{
    m_scaling   = value;
}

T100Vector3 T100DX12Camera::GetScaling()
{
    return m_scaling;
}
