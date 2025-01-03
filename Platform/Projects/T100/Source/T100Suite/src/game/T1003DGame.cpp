#include "T1003DGame.h"

T1003DGame::T1003DGame()
{
    //ctor
    create();
}

T1003DGame::~T1003DGame()
{
    //dtor
    destroy();
}

T100VOID T1003DGame::create()
{

}

T100VOID T1003DGame::destroy()
{

}

T100VOID T1003DGame::setHWND(HWND hwnd)
{
    m_hwnd  = hwnd;
}

T100BOOL T1003DGame::show_lobby()
{

}

T100BOOL T1003DGame::run()
{
    m_renderer.run();
}
