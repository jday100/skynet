#include "T100Game.h"

T100Game::T100Game()
{
    //ctor
}

T100Game::~T100Game()
{
    //dtor
}

T100VOID T100Game::Create(HWND hwnd, UINT width, UINT height)
{
    m_dx12  = T100NEW T100DX12();

    m_dx12->Create(hwnd, width, height);
}

T100VOID T100Game::Destroy()
{

}

T100VOID T100Game::Load()
{
    m_dx12->Init();
    m_dx12->Load(m_scene->entities);
}

T100VOID T100Game::Release()
{

}

T100VOID T100Game::Render()
{
    m_dx12->Update();
    m_dx12->Render();
}

T100VOID T100Game::SetSize(UINT width, UINT height)
{
    m_dx12->SetSize(width, height);
}

T100VOID T100Game::OnKeyDown(UINT8 key)
{
    m_dx12->OnKeyDown(key);
}

T100VOID T100Game::OnKeyUp(UINT8 key)
{
    m_dx12->OnKeyUp(key);
}

T100VOID T100Game::SetScene(T100Scene* scene)
{
    m_scene     = scene;
}

T100Scene* T100Game::GetScene()
{
    return m_scene;
}
