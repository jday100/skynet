#include "T100Camera.h"

#ifndef NOMINMAX

#ifndef max
#define max(a,b)            (((a) > (b)) ? (a) : (b))
#endif

#ifndef min
#define min(a,b)            (((a) < (b)) ? (a) : (b))
#endif

#endif  /* NOMINMAX */

T100Camera::T100Camera() :
    m_initialPosition(0, 0, 0),
    m_position(m_initialPosition),
    m_yaw(XM_PI),
    m_pitch(0.0f),
    m_lookDirection(0, 0, -1),
    m_upDirection(0, 1, 0),
    m_moveSpeed(20.0f),
    m_turnSpeed(XM_PIDIV2),
    m_keysPressed{}
{
    //ctor
}

T100Camera::~T100Camera()
{
    //dtor
}

void T100Camera::Init(XMFLOAT3 position)
{
    m_initialPosition = position;
    Reset();
}

void T100Camera::SetMoveSpeed(float unitsPerSecond)
{
    m_moveSpeed = unitsPerSecond;
}

void T100Camera::SetTurnSpeed(float radiansPerSecond)
{
    m_turnSpeed = radiansPerSecond;
}

void T100Camera::Reset()
{
    m_position = m_initialPosition;
    m_yaw = XM_PI;
    m_pitch = 0.0f;
    m_lookDirection = { 0, 0, -1 };
}

void T100Camera::Update(float elapsedSeconds)
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

XMMATRIX T100Camera::GetViewMatrix()
{
    return XMMatrixLookToRH(XMLoadFloat3(&m_position), XMLoadFloat3(&m_lookDirection), XMLoadFloat3(&m_upDirection));
}

XMMATRIX T100Camera::GetProjectionMatrix(float fov, float aspectRatio, float nearPlane, float farPlane)
{
    return XMMatrixPerspectiveFovRH(fov, aspectRatio, nearPlane, farPlane);
}

void T100Camera::OnKeyDown(WPARAM key)
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

void T100Camera::OnKeyUp(WPARAM key)
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
