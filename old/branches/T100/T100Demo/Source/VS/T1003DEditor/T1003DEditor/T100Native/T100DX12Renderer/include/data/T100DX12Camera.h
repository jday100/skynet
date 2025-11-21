#ifndef T100DX12CAMERA_H
#define T100DX12CAMERA_H

#include <vector>
#include "T100Common.h"
#include "T1003DCommon.h"
#include "dx12/T100DX12Header.h"
#include "link/T100CameraInstance.h"

class T100DX12Studio;

#define     T100DX12_CAMERA_VECTOR          std::vector<T100DX12Camera*>

class T100DX12Camera : public T100CameraInstance
{
    public:
        T100DX12Camera();
        virtual ~T100DX12Camera();

        T100VOID                            Setup(T1003DCamera*);

        T100VOID                            Clear();
        T100VOID                            Reset();

        T100VOID                            SetStudioPtr(T100DX12Studio*);
        T100DX12Studio*                     GetStudioPtr();

        virtual T100VOID                    GetViewMatrix(T100Matrix4f&);
        virtual T100VOID                    GetProjectionMatrix(T100Matrix4f&);

        virtual T100VOID                    GetViewMatrix(XMMATRIX&);
        virtual T100VOID                    GetProjectionMatrix(XMMATRIX&);

        virtual T100VOID                    GetTranslation(T100Matrix4f&);
        virtual T100VOID                    Unproject(const T100Vector3f&, T100FLOAT, T100FLOAT, T100UINT, T100UINT, T100FLOAT, T100FLOAT, const T100Matrix4f&, const T100Matrix4f&, const T100Matrix4f&, T100Vector3f&);

        T100VOID                            SetPosition(T100FLOAT, T100FLOAT, T100FLOAT);
        T100VOID                            SetPosition(T100Vector3f&);

        T100VOID                            SetRotation(T100FLOAT, T100FLOAT, T100FLOAT);
        T100VOID                            SetRotation(T100Vector3f&);

    protected:
        T100DX12Studio*                     m_studioPtr         = T100NULL;

        T1003D_COORDINATE_SYSTEM_TYPE       m_type;
        T100Vector3f                        m_lookat;
        T100Vector3f                        m_up;

        T100FLOAT                           m_fov;
        T100FLOAT                           m_aspectRatio;
        T100FLOAT                           m_nearPlane;
        T100FLOAT                           m_farPlane;

        XMMATRIX                            m_projection;
        XMMATRIX                            m_view;

        T100Vector3f                        m_position;

        T100VOID                            BuildView();

    private:
};

#endif // T100DX12CAMERA_H
