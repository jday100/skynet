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

T100BOOL T100Game::Create(HWND hwnd)
{
    m_dx12  = T100NEW T100DX12();

    m_dx12->Create(hwnd);
}

T100BOOL T100Game::Render()
{

}
