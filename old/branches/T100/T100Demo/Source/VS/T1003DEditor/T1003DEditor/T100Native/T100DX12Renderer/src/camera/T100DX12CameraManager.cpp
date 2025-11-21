#include "camera/T100DX12CameraManager.h"

T100DX12CameraManager::T100DX12CameraManager(T100DX12Studio* studio) :
    m_studioPtr(studio)
{
    //ctor
}

T100DX12CameraManager::~T100DX12CameraManager()
{
    //dtor
}

T100VOID T100DX12CameraManager::SetCameraPtr(T1003DCamera* cameraPtr)
{
    m_cameraPtr = Convert(cameraPtr);
}

T1003DCamera* T100DX12CameraManager::GetCameraPtr()
{
    if(!m_cameraPtr)return T100NULL;
    return m_cameraPtr->GetSource();
}

T100DX12Camera* T100DX12CameraManager::GetCameraInstancePtr()
{
    return m_cameraPtr;
}

T100DX12Camera* T100DX12CameraManager::Convert(T1003DCamera* camera)
{
    T100DX12Camera*     resultPtr       = T100NEW T100DX12Camera();

    resultPtr->SetStudioPtr(m_studioPtr);
    resultPtr->Setup(camera);

    camera->SetInstancePtr(resultPtr);

    return resultPtr;
}
