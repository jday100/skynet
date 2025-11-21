#include "core/T100DX12Studio.h"

#include "dx12/T100DX12Tools.h"

T100DX12Studio::T100DX12Studio() :
    T100DX12Area(),
    m_timer(),
    m_fenceValue(0),
    m_fenceEvent(T100NULL),
    m_meshManager(this),
    m_lightManager(this),
    m_frameManager(this),
    m_cameraManager(this),
    m_contextManager(this)
{
    //ctor
}

T100DX12Studio::~T100DX12Studio()
{
    //dtor
}

T100DX12MeshManager& T100DX12Studio::GetMeshManager()
{
    return m_meshManager;
}

T100DX12LightManager& T100DX12Studio::GetLightManager()
{
    return m_lightManager;
}

T100DX12FrameManager& T100DX12Studio::GetFrameManager()
{
    return m_frameManager;
}

T100DX12CameraManager& T100DX12Studio::GetCameraManager()
{
    return m_cameraManager;
}

T100DX12ContextManager& T100DX12Studio::GetContextManager()
{
    return m_contextManager;
}

T100VOID T100DX12Studio::Create(HWND hwnd, T100UINT width, T100UINT height)
{
    T100DX12Area::Create(hwnd, width, height);
    m_frameManager.Create();
}

T100VOID T100DX12Studio::Destroy()
{
    m_frameManager.Destroy();
    T100DX12Area::Destroy();
}

T100VOID T100DX12Studio::Start()
{

    T100DX12Area::Start();

    m_frameManager.Start();

    ThrowIfFailed(m_device->CreateCommandList(0, D3D12_COMMAND_LIST_TYPE_DIRECT, m_commandAllocator.Get(), nullptr, IID_PPV_ARGS(&m_commandList)));
    ThrowIfFailed(m_commandList->Close());

    CreateFence();

    m_meshManager.Start();


    //m_bundleTest.m_width    = GetWidth();
    //m_bundleTest.m_height   = GetHeight();
    //m_bundleTest.init(m_hwnd);
}

T100VOID T100DX12Studio::Stop()
{
    m_meshManager.Stop();
    T100DX12Area::Stop();
}

T100VOID T100DX12Studio::Update()
{

    m_timer.Tick();

    m_meshManager.Update();
    m_frameManager.Update();


    //m_bundleTest.update();
}

T100VOID T100DX12Studio::Render()
{

    m_frameManager.Render();

    ThrowIfFailed(m_swapChain->Present(1, 0));
    m_frameIndex = m_swapChain->GetCurrentBackBufferIndex();

    Waiting();


    //m_bundleTest.render();
}

T100VOID T100DX12Studio::CreateFence()
{
    ThrowIfFailed(m_device->CreateFence(0, D3D12_FENCE_FLAG_NONE, IID_PPV_ARGS(&m_fence)));
    m_fenceValue = 1;

    m_fenceEvent = CreateEvent(T100NULL, T100FALSE, T100FALSE, T100NULL);
    if (m_fenceEvent == T100NULL)
    {
        ThrowIfFailed(HRESULT_FROM_WIN32(GetLastError()));
    }
}

T100VOID T100DX12Studio::Waiting()
{
    const UINT64        fence = m_fenceValue;

    ThrowIfFailed(m_commandQueue->Signal(m_fence.Get(), fence));
    m_fenceValue++;

    if(m_fence->GetCompletedValue() < fence)
    {
        ThrowIfFailed(m_fence->SetEventOnCompletion(fence, m_fenceEvent));
        WaitForSingleObject(m_fenceEvent, INFINITE);
    }
}

T100VOID T100DX12Studio::Append(T1003DMesh* mesh)
{
    m_meshManager.Append(mesh);
}

T100VOID T100DX12Studio::Remove(T1003DMesh* mesh)
{
    m_meshManager.Remove(mesh);
}

T100VOID T100DX12Studio::SetCameraPtr(T1003DCamera* cameraPtr)
{
    m_cameraManager.SetCameraPtr(cameraPtr);
}

T1003DCamera* T100DX12Studio::GetCameraPtr()
{
    return m_cameraManager.GetCameraPtr();
}

T1003DTimer& T100DX12Studio::GetTimer()
{
    return m_timer;
}

T100DX12Camera* T100DX12Studio::GetCameraInstancePtr()
{
    return m_cameraManager.GetCameraInstancePtr();
}

T100UINT T100DX12Studio::GetWidth()
{
    return m_width;
}

T100UINT T100DX12Studio::GetHeight()
{
    return m_height;
}

T100VOID T100DX12Studio::SetBundle(T1003DMesh* meshPtr)
{
    m_meshManager.SetBundle(meshPtr);
}
