#ifndef T100CAMERA_H
#define T100CAMERA_H

#include "directxmath.h"
#include "T100Common.h"
using namespace DirectX;

class T100Camera
{
    public:
        T100Camera();
        virtual ~T100Camera();

        T100VOID            Init(XMFLOAT3);
        T100VOID            Update(float);
        XMMATRIX            GetViewMatrix();
        XMMATRIX            GetProjectionMatrix(float fov, float aspectRatio, float nearPlane = 1.0f, float farPlane = 1000.0f);
        T100VOID            SetMoveSpeed(float);
        T100VOID            SetTurnSpeed(float);

        T100VOID            OnKeyDown(WPARAM);
        T100VOID            OnKeyUp(WPARAM);

    protected:

    private:
        T100VOID            Reset();

        struct KeysPressed
        {
            bool    w;
            bool    a;
            bool    s;
            bool    d;

            bool    left;
            bool    right;
            bool    up;
            bool    down;
        };

        XMFLOAT3            m_initialPosition;
        XMFLOAT3            m_position;
        float               m_yaw;
        float               m_pitch
        XMFLOAT3            m_lookDirection;
        XMFLOAT3            m_upDirection;
        float               m_moveSpeed;
        float               m_turnSpeed;

        KeysPressed         m_keysPressed;
};

#endif // T100CAMERA_H
