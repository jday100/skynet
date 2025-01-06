#ifndef T100SIMPLECAMERA_H
#define T100SIMPLECAMERA_H

#include "stdafx.h"
#include "T100DirectXMath.h"

using namespace DirectX;

class T100SimpleCamera
{
    public:
        T100SimpleCamera();
        virtual ~T100SimpleCamera();

        void            Init(XMFLOAT3 position);
        void            Update(float elapsedSeconds);
        XMMATRIX        GetViewMatrix();
        XMMATRIX        GetProjectionMatrix(float fov, float aspectRatio, float nearPlane = 1.0f, float farPlane = 1000.0f);
        void            SetMoveSpeed(float unitsPerSecond);
        void            SetTurnSpeed(float radiansPerSecond);

        void            OnKeyDown(WPARAM key);
        void            OnKeyUp(WPARAM key);

    protected:

    private:
        void            Reset();

        struct KeysPressed
        {
            bool w;
            bool a;
            bool s;
            bool d;

            bool left;
            bool right;
            bool up;
            bool down;
        };

        XMFLOAT3        m_initialPosition;
        XMFLOAT3        m_position;
        float           m_yaw;
        float           m_pitch;
        XMFLOAT3        m_lookDirection;
        XMFLOAT3        m_upDirection;
        float           m_moveSpeed;
        float           m_turnSpeed;

        KeysPressed     m_keysPressed;
};

#endif // T100SIMPLECAMERA_H
