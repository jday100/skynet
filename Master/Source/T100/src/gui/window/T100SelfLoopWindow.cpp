#include "gui/window/T100SelfLoopWindow.h"

T100SelfLoopWindow::T100SelfLoopWindow() :
    T100Window()
{
    //ctor
}

T100SelfLoopWindow::T100SelfLoopWindow(T100ApplicationEventHandler* app, T100Window* parent) :
    T100Window(app, parent)
{
    //ctor
}

T100SelfLoopWindow::~T100SelfLoopWindow()
{
    //dtor
}

T100VOID T100SelfLoopWindow::Create(T100ApplicationEventHandler* app, T100Window* parent)
{
    T100Window::Create(app, parent);
}

LRESULT CALLBACK DefaultSelfLoopWindowProcedure (HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    T100WindowMessageData               data                = {hwnd, message, wParam, lParam};

    return DefWindowProc (hwnd, message, wParam, lParam);
}
