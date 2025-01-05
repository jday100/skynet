#include "T100Game.h"

T100Game::T100Game(HINSTANCE hThisInstance, HINSTANCE hPrevInstance, LPSTR lpszArgument, int nCmdShow)
    :T100Frame(hThisInstance, hPrevInstance, lpszArgument, nCmdShow)
{
    //ctor
}

T100Game::~T100Game()
{
    //dtor
}

T100VOID T100Game::Create(LPSTR name, LPSTR title)
{
    T100Frame::Create(name, title, T100Game::GameWindowProcedure);
}

LRESULT CALLBACK T100Game::GameWindowProcedure(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch(message)
    {
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hwnd, message, wParam, lParam);
    }
    return 0;
}
