#ifndef T100CAMERAINSTANCE_H
#define T100CAMERAINSTANCE_H

#include "T100Common.h"
#include "vector/T100Vector3f.h"
#include "matrix/T100Matrix4f.h"
#include "T100Instance.h"

class T1003DCamera;

class T100CameraInstance : public T100Instance
{
    public:
        T100CameraInstance();
        virtual ~T100CameraInstance();

        virtual T100VOID            Clear() = 0;

        virtual T100VOID            Reset() = 0;

        virtual T100VOID            GetViewMatrix(T100Matrix4f&) = 0;
        virtual T100VOID            GetProjectionMatrix(T100Matrix4f&) = 0;

        virtual T100VOID            GetTranslation(T100Matrix4f&) = 0;
        virtual T100VOID            Unproject(const T100Vector3f&, T100FLOAT, T100FLOAT, T100UINT, T100UINT, T100FLOAT, T100FLOAT, const T100Matrix4f&, const T100Matrix4f&, const T100Matrix4f&, T100Vector3f&) = 0;

        T100VOID                    SetSource(T1003DCamera*);
        T1003DCamera*               GetSource();

    protected:
        T1003DCamera*               m_source            = T100NULL;

    private:

};

#endif // T100CAMERAINSTANCE_H
