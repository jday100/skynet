#ifndef T100DX12CAMERAMANAGER_H
#define T100DX12CAMERAMANAGER_H

#include "link/T1003DCamera.h"
#include "data/T100DX12Camera.h"

class T100DX12Studio;

class T100DX12CameraManager
{
    public:
        T100DX12CameraManager(T100DX12Studio*);
        virtual ~T100DX12CameraManager();

        virtual T100VOID        SetCameraPtr(T1003DCamera*);
        T1003DCamera*           GetCameraPtr();

        T100DX12Camera*         GetCameraInstancePtr();

    protected:
        T100DX12Studio*         m_studioPtr         = T100NULL;
        T100DX12Camera*         m_cameraPtr         = T100NULL;

    private:
        T100DX12Camera*         Convert(T1003DCamera*);
};

#endif // T100DX12CAMERAMANAGER_H
