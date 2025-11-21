#ifndef T1003DCAMERA_H
#define T1003DCAMERA_H

#include <vector>
#include "T100Common.h"
#include "T1003DCommon.h"
#include "T1003DObject.h"
#include "T100CameraInstance.h"

#define     T1003DCAMERA_VECTOR             std::vector<T1003DCamera*>

class T1003DCamera : public T1003DObject
{
    public:
        T1003DCamera(T1003D_COORDINATE_SYSTEM_TYPE = T1003D_COORDINATE_SYSTEM_LEFT_HAND);
        virtual ~T1003DCamera();

        T100WSTRING                         Name;
        T1003D_COORDINATE_SYSTEM_TYPE       GetType();

        T100VOID                            Reset();

        T100VOID                            SetLookAt(T100FLOAT, T100FLOAT, T100FLOAT);
        T100VOID                            SetLookAt(T100Vector3f&);
        T100Vector3f&                       GetLookAt();

        T100VOID                            SetUp(T100FLOAT, T100FLOAT, T100FLOAT);
        T100VOID                            SetUp(T100Vector3f&);
        T100Vector3f&                       GetUp();

        T100VOID                            SetFov(T100FLOAT);
        T100FLOAT                           GetFov();
        T100VOID                            SetAspectRatio(T100FLOAT);
        T100FLOAT                           GetAspectRatio();
        T100VOID                            SetNearPlane(T100FLOAT);
        T100FLOAT                           GetNearPlane();
        T100VOID                            SetFarPlane(T100FLOAT);
        T100FLOAT                           GetFarPlane();

        T100VOID                            GetViewMatrix(T100Matrix4f&);
        T100VOID                            GetProjectionMatrix(T100Matrix4f&);

        T100VOID                            GetTranslation(T100Matrix4f&);
        T100VOID                            Unproject(const T100Vector3f&, T100FLOAT, T100FLOAT, T100UINT, T100UINT, T100FLOAT, T100FLOAT, const T100Matrix4f&, const T100Matrix4f&, const T100Matrix4f&, T100Vector3f&);

        T100VOID                            SetPosition(T100FLOAT, T100FLOAT, T100FLOAT);
        T100VOID                            SetPosition(T100Vector3f&);

        T100VOID                            SetRotation(T100FLOAT, T100FLOAT, T100FLOAT);
        T100VOID                            SetRotation(T100Vector3f&);

        T100VOID                            SetInstancePtr(T100CameraInstance*);
        T100CameraInstance*                 GetInstancePtr();

    protected:
        T1003D_COORDINATE_SYSTEM_TYPE       m_type;
        T100Vector3f                        m_lookat;
        T100Vector3f                        m_up;

        T100FLOAT                           m_fov;
        T100FLOAT                           m_aspectRatio;
        T100FLOAT                           m_nearPlane;
        T100FLOAT                           m_farPlane;

    private:
        T100CameraInstance*                 m_instancePtr           = T100NULL;
};

#endif // T1003DCAMERA_H
