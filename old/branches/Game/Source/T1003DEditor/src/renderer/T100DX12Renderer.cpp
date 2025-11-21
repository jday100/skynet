#include "T100DX12Renderer.h"

T100DX12Renderer::T100DX12Renderer() :
    m_dx12()
{
    //ctor
}

T100DX12Renderer::~T100DX12Renderer()
{
    //dtor
}

T100VOID T100DX12Renderer::Create(HWND hwnd, UINT width, UINT height)
{
    m_dx12.Create(hwnd, width, height);
}

T100VOID T100DX12Renderer::Destroy()
{
    m_dx12.Destroy();
}

T100VOID T100DX12Renderer::SetSize(UINT width, UINT height)
{
    m_dx12.SetSize(width, height);
}

T100VOID T100DX12Renderer::Start()
{
    m_dx12.Start();
}

T100VOID T100DX12Renderer::Stop()
{
    m_dx12.Stop();
}

T100VOID T100DX12Renderer::Update()
{
    m_dx12.Update();
}

T100VOID T100DX12Renderer::Render()
{
    m_dx12.Render();
}

T100VOID T100DX12Renderer::SetConfig(T100DX12Config* config)
{
    m_dx12.SetConfig(config);
}

T100DX12Config* T100DX12Renderer::GetConfig()
{
    return m_dx12.GetConfig();
}

T100VOID T100DX12Renderer::SetScene(T100DX12Scene* scene)
{
    m_dx12.SetScene(scene);
}

T100DX12Scene* T100DX12Renderer::GetScene()
{
    return m_dx12.GetScene();
}

T100DX12Camera& T100DX12Renderer::GetCamera()
{
    return m_dx12.m_camera;
}

T100DX12Timer& T100DX12Renderer::GetTimer()
{
    return m_dx12.m_timer;
}
