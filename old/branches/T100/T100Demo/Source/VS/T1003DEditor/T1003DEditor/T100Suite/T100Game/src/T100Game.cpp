#include "T100Game.h"

T100Game::T100Game() :
    m_input(),
    m_motion()
{
    //ctor
    init();
}

T100Game::~T100Game()
{
    //dtor
    uninit();
}

T100VOID T100Game::init()
{
    m_dx12Ptr = T100NEW T100DX12Renderer();
}

T100VOID T100Game::uninit()
{
    T100SAFE_DELETE m_dx12Ptr;
}

T1003DRenderer* T100Game::GetRenderer()
{
    return m_dx12Ptr;
}

T100VOID T100Game::SetScenePtr(T100GameScene* scenePtr)
{
    m_scenePtr  = scenePtr;
}

T100GameScene* T100Game::GetScenePtr()
{
    return m_scenePtr;
}

T100GameInput& T100Game::GetInput()
{
    return m_input;
}

T100VOID T100Game::Create(T1003DWindowHandle handle, T100UINT width, T100UINT height)
{
    m_dx12Ptr->Create(handle, width, height);

    m_scenePtr->Create();

    m_scenePtr->AppendStaticMeshes();
    m_scenePtr->AppendDynamicsMeshes();

    m_scenePtr->LoadStaticMeshes(m_dx12Ptr);
    m_scenePtr->LoadDynamicsMeshes(m_dx12Ptr);
}

T100VOID T100Game::Destroy()
{
    m_scenePtr->Destroy();
    m_dx12Ptr->Destroy();
}

T100VOID T100Game::SetSize(T100UINT width, T100UINT height)
{
    m_dx12Ptr->SetSize(width, height);
}

T100VOID T100Game::Start()
{
    m_dx12Ptr->Start();
}

T100VOID T100Game::Stop()
{
    m_dx12Ptr->Stop();
}

T100VOID T100Game::Update()
{
    m_dx12Ptr->Update();
}

T100VOID T100Game::Render()
{
    m_dx12Ptr->Render();
}

T100VOID T100Game::SetConfigPtr(T1003DConfig* configPtr)
{
    m_dx12Ptr->SetConfigPtr(configPtr);
}

T1003DConfig* T100Game::GetConfigPtr()
{
    return m_dx12Ptr->GetConfigPtr();
}

T100VOID T100Game::Append(T1003DMesh* meshPtr)
{
    m_dx12Ptr->Append(meshPtr);
}

T100VOID T100Game::Remove(T1003DMesh* meshPtr)
{
    m_dx12Ptr->Remove(meshPtr);
}

T1003DTimer& T100Game::GetTimer()
{
    return m_dx12Ptr->GetTimer();
}

T100VOID T100Game::SetCameraPtr(T1003DCamera* camera)
{
    m_motion.SetCameraPtr(camera);
    m_input.SetMotionPtr(&m_motion);
    m_dx12Ptr->SetCameraPtr(camera);
}

T1003DCamera* T100Game::GetCameraPtr()
{
    return m_motion.GetCameraPtr();
}
