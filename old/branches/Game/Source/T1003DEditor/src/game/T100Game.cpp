#include "T100Game.h"

#include <thread>
#include "T100Debug.h"


T100Game::T100Game() :
    m_renderer()
{
    //ctor
}

T100Game::~T100Game()
{
    //dtor
}

T100VOID T100Game::Create(HWND hwnd, UINT width, UINT height)
{
    m_inputPtr  = T100NEW T100DX12Input();
    m_motionPtr = T100NEW T100DX12Motion();
    m_renderer.Create(hwnd, width, height);

    m_motionPtr->SetCameraPtr(&m_renderer.GetCamera());
    m_inputPtr->SetMotionPtr(m_motionPtr);
}

T100VOID T100Game::Destroy()
{
    m_renderer.Destroy();
    T100SAFE_DELETE m_motionPtr;
    T100SAFE_DELETE m_inputPtr;
}

T100VOID T100Game::SetSize(UINT width, UINT height)
{
    m_renderer.SetSize(width, height);
}

T100VOID T100Game::Start()
{
    m_renderer.Start();
}

T100VOID T100Game::Stop()
{
    m_renderer.Stop();
}

T100VOID T100Game::Update()
{
    m_renderer.Update();
}

T100VOID T100Game::Render()
{
    //std::this_thread::sleep_for(std::chrono::milliseconds(500));
    m_renderer.Render();
    //DEBUGPRINT("Rendering ...");

}

T100VOID T100Game::SetScene(T100DX12Scene* scene)
{
    m_renderer.SetScene(scene);
}

T100DX12Scene* T100Game::GetScene()
{
    return m_renderer.GetScene();
}

T100VOID T100Game::SetInputPtr(T100DX12Input* input)
{
    m_inputPtr  = input;
}

T100DX12Input* T100Game::GetInputPtr()
{
    return m_inputPtr;
}

T100DX12Renderer* T100Game::GetRenderer()
{
    return &m_renderer;
}

T100VOID T100Game::Move()
{
    m_inputPtr->OnKeyDown('E');
}
