#ifndef T100DX12CAMERA_H
#define T100DX12CAMERA_H

#include <windows.h>
#include "dx12/DirectXMath.h"
#include "T100Common.h"
#include "common/T100DX12Common.h"
#include "math/T100Vector3.h"

using namespace DirectX;

class T100DX12Camera
{
    friend class T100DX12Scene;
    public:
        T100DX12Camera();
        virtual ~T100DX12Camera();

        T100VOID                            Reset();

        T100VOID                            SetCoordinateSystemType(T100DX12_COORDINATE_SYSTEM_TYPE);
        T100DX12_COORDINATE_SYSTEM_TYPE     GetCoordinateSystemType();

        T100VOID                            SetProjectionType(T100DX12_PROJECTION_TYPE);
        T100DX12_PROJECTION_TYPE            GetProjectionType();

        T100VOID                            SetFov(T100FLOAT);
        T100FLOAT                           GetFov();

        T100VOID                            SetAspectRatio(T100FLOAT);
        T100FLOAT                           GetAspectRatio();

        T100VOID                            SetNearPlane(T100FLOAT);
        T100FLOAT                           GetNearPlane();

        T100VOID                            SetFarPlane(T100FLOAT);
        T100FLOAT                           GetFarPlane();

        T100VOID                            SetWidth(T100FLOAT);
        T100FLOAT                           GetWidth();

        T100VOID                            SetHeight(T100FLOAT);
        T100FLOAT                           GetHeight();

        T100VOID                            SetPosition(T100FLOAT, T100FLOAT, T100FLOAT);
        T100VOID                            SetPosition(T100Vector3);
        T100Vector3                         GetPosition();

        T100VOID                            SetRotation(T100FLOAT, T100FLOAT, T100FLOAT);
        T100VOID                            SetRotation(T100Vector3);
        T100Vector3                         GetRotation();

        T100VOID                            SetScaling(T100FLOAT, T100FLOAT, T100FLOAT);
        T100VOID                            SetScaling(T100Vector3);
        T100Vector3                         GetScaling();

        T100Vector3                         GetLookAt();
        T100Vector3                         GetUp();

        void                                Init(XMFLOAT3 position);
        void                                Update(float elapsedSeconds);
        XMMATRIX&                           GetViewMatrix();
        XMMATRIX&                           GetProjectionMatrix();
        void                                SetMoveSpeed(float unitsPerSecond);
        void                                SetTurnSpeed(float radiansPerSecond);

        void                                OnKeyDown(WPARAM key);
        void                                OnKeyUp(WPARAM key);

        void                                GetScreenToViewRay(T100UINT, T100UINT, T100Vector3&, T100Vector3&);

    protected:
        XMMATRIX                            m_view;
        XMMATRIX                            m_projection;

        float                               m_fov;
        float                               m_aspectRatio;
        float                               m_nearPlane;
        float                               m_farPlane;

        float                               m_width;
        float                               m_height;

        T100Vector3                         m_rotation;
        T100Vector3                         m_scaling;

        T100VOID                            UpdateView();
        T100VOID                            UpdateProjection();

    private:
        T100DX12_COORDINATE_SYSTEM_TYPE     m_coordinateType    = T100DX12_COORDINATE_SYSTEM_LEFT_HAND;
        T100DX12_PROJECTION_TYPE            m_projectionType    = T100DX12_PERSPECTIVE_PROJECTION;

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

#endif // T100DX12CAMERA_H
