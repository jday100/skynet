#include "T100DX12Renderer.h"

T100DX12Renderer::T100DX12Renderer() :
    T1003DRenderer()
{
    //ctor
    init();
}

T100DX12Renderer::~T100DX12Renderer()
{
    //dtor
    uninit();
}

T100VOID T100DX12Renderer::init()
{
    m_studioPtr = T100NEW T100DX12Studio();
}

T100VOID T100DX12Renderer::uninit()
{
    T100SAFE_DELETE m_studioPtr;
}

T100VOID T100DX12Renderer::Create(T1003DWindowHandle handle, T100UINT width, T100UINT height)
{
    m_studioPtr->Create(handle.HWND, width, height);
}

T100VOID T100DX12Renderer::Destroy()
{
    m_studioPtr->Destroy();
}

T100VOID T100DX12Renderer::SetSize(T100UINT width, T100UINT height)
{
    m_studioPtr->SetSize(width, height);
}

T100VOID T100DX12Renderer::Start()
{
    m_studioPtr->Start();
}

T100VOID T100DX12Renderer::Stop()
{
    m_studioPtr->Stop();
}

T100VOID T100DX12Renderer::Update()
{
    m_studioPtr->Update();
}

T100VOID T100DX12Renderer::Render()
{
    m_studioPtr->Render();
}

T100VOID T100DX12Renderer::SetConfigPtr(T1003DConfig* configPtr)
{
    m_studioPtr->SetConfigPtr(configPtr);
}

T1003DConfig* T100DX12Renderer::GetConfigPtr()
{
    return m_studioPtr->GetConfigPtr();
}

T100VOID T100DX12Renderer::SetCameraPtr(T1003DCamera* cameraPtr)
{
    m_studioPtr->SetCameraPtr(cameraPtr);
}

T1003DCamera* T100DX12Renderer::GetCameraPtr()
{
    return m_studioPtr->GetCameraPtr();
}

T100VOID T100DX12Renderer::Append(T1003DMesh* meshPtr)
{
    m_studioPtr->Append(meshPtr);
}

T100VOID T100DX12Renderer::Remove(T1003DMesh* meshPtr)
{
    m_studioPtr->Remove(meshPtr);
}

T100UINT T100DX12Renderer::GetWidth()
{
    return m_studioPtr->GetWidth();
}

T100UINT T100DX12Renderer::GetHeight()
{
    return m_studioPtr->GetHeight();
}

T100FLOAT T100DX12Renderer::GetAspectRatio()
{
    return m_studioPtr->GetAspectRatio();
}

T100VOID T100DX12Renderer::SetBundle(T1003DMesh* meshPtr)
{
    m_studioPtr->SetBundle(meshPtr);
}

T1003DTimer& T100DX12Renderer::GetTimer()
{
    return m_studioPtr->GetTimer();
}
