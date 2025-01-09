#include "T100Game.h"

T100Game::T100Game()
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

}

T100VOID T100Game::uninit()
{

}

T100BOOL T100Game::Create(HWND hwnd, UINT width, UINT height)
{
    m_dx12  = T100NEW T100DX12();

    m_dx12->Create(hwnd, width, height);
}

T100BOOL T100Game::Start()
{
    return m_dx12->Init();
}

T100BOOL T100Game::Render()
{
    m_dx12->Update();
    m_dx12->Render();
}

T100VOID T100Game::OnKeyDown(UINT8 key)
{
    m_dx12->OnKeyDown(key);
}

T100VOID T100Game::OnKeyUp(UINT8 key)
{
    m_dx12->OnKeyUp(key);
}
