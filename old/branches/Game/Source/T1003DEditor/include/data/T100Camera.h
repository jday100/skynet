#ifndef T100CAMERA_H
#define T100CAMERA_H

#include <vector>
#include "T100Common.h"
#include "math/T100Vector3.h"

class T100DX12Camera;

#define     T100CAMERA_VECTOR           std::vector<T100Camera*>

class T100Camera
{
    public:
        T100Camera();
        virtual ~T100Camera();

        T100WSTRING                 Name;

        T100VOID                    SetPosition(T100FLOAT, T100FLOAT, T100FLOAT);
        T100VOID                    SetPosition(T100Vector3);
        T100Vector3                 GetPosition();

        T100VOID                    SetRotation(T100FLOAT, T100FLOAT, T100FLOAT);
        T100VOID                    SetRotation(T100Vector3);
        T100Vector3                 GetRotation();

        T100VOID                    SetScaling(T100FLOAT, T100FLOAT, T100FLOAT);
        T100VOID                    SetScaling(T100Vector3);
        T100Vector3                 GetScaling();

    protected:
        T100DX12Camera*             m_camera            = T100NULL;

        T100Vector3                 m_position;
        T100Vector3                 m_rotation;
        T100Vector3                 m_scaling;

    private:
};

#endif // T100CAMERA_H
