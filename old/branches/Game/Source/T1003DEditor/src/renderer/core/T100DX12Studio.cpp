#include "T100DX12Studio.h"

#include "T100DX12Tools.h"

T100DX12Studio::T100DX12Studio() :
    T100DX12Area(),
    m_frame_manager(this),
    m_model_manager(this),
    m_scene_manager(this),
    m_light_manager(this),
    m_context_manager(this),
    m_dynamic(this)
{
    //ctor
}

T100DX12Studio::~T100DX12Studio()
{
    //dtor
}

T100DX12HeapManager& T100DX12Studio::GetHeapManager()
{
    return m_heap_manager;
}

T100DX12ModelManager& T100DX12Studio::GetModelManager()
{
    return m_model_manager;
}

T100DX12LightManager& T100DX12Studio::GetLightManager()
{
    return m_light_manager;
}

T100DX12Camera& T100DX12Studio::GetCamera()
{
    return m_camera;
}

T100VOID T100DX12Studio::SetScene(T100DX12Scene* scene)
{
    m_scene_manager.SetScene(scene);
}

T100DX12Scene* T100DX12Studio::GetScene()
{
    return m_scene_manager.GetScene();
}

T100VOID T100DX12Studio::Create(HWND hwnd, T100UINT width, T100UINT height)
{
    T100DX12Area::Create(hwnd, width, height);

    m_camera.SetCoordinateSystemType(m_config->DefaultCoordinateSystemType);
    m_camera.SetProjectionType(m_config->DefaultProjectionType);

    m_camera.SetWidth(width);
    m_camera.SetHeight(height);

    m_camera.SetFov(0.8);
    m_camera.SetAspectRatio(m_aspectRatio);

    m_camera.SetNearPlane(1);
    m_camera.SetFarPlane(1000);

    //m_dynamic.Create(hwnd, width, height);
}

T100VOID T100DX12Studio::Start()
{
    //
    StudioStart();
    //    m_triangle.Start();

    //    m_line.Start();

    //
    //    m_dynamic.Start();
}

T100VOID T100DX12Studio::Stop()
{
    //
    StudioStop();
}

T100VOID T100DX12Studio::Update()
{
    //
    m_scene_manager.Update();
    //
    m_frame_manager.Update();

    //    m_triangle.Update();
    //    m_line.Update();

    //    m_dynamic.Update();
}

T100VOID T100DX12Studio::Render()
{
    //
    m_frame_manager.Render();

    //    m_triangle.Render();

    //    m_line.Render();

    //    m_dynamic.Render();
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

T100VOID T100DX12Studio::InitCbvSrvHeapSize()
{
    T100UINT        size;

    m_scene_manager.GetScene()->CountStaticHeapSize();

    size    = m_scene_manager.GetScene()->m_cbvSrvHeapLength * 3;
    size    = m_frameCount * size + 1;
    size    = 256 * 256;

    if(size < 256){
        size    = 256;
    }else if(size < 256 * 256){
        size    = 256 * 256;
    }else if(size < 256 * 256 * 256){
        size    = 256 * 256 * 256;
    }else if(size < 256 * 256 * 256 * 256 - 1){
        size    = 256 * 256 * 256 * 256 - 1;
    }

    m_config->CbvSrvHeapSize    = size;
    m_config->DsvHeapSize       = m_scene_manager.GetScene()->m_dsvHeapLength * 3 + 1 + 256;
    m_config->SamplerHeapSize   = m_scene_manager.GetScene()->m_samplerHeapLength * 3 + 1 + 256;
}

T100VOID T100DX12Studio::StudioStart()
{
    m_camera.Init({0, 5, 30});

    m_frame_manager.Start();
    m_scene_manager.Start();
    InitCbvSrvHeapSize();
    T100DX12Area::Start();
    m_frame_manager.CreateCommandAllocators();
    CreateCommandAllocator();
    CreateFence();

    m_scene_manager.Load();

    //m_discrete.Start();
}

T100VOID T100DX12Studio::StudioStop()
{
    T100DX12Area::Stop();
    m_scene_manager.Stop();
    m_frame_manager.Stop();
}

T100VOID T100DX12Studio::StudioUpdate()
{
}

T100VOID T100DX12Studio::StudioRender()
{
}

