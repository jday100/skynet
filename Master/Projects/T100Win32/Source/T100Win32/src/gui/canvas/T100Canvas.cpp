#include "T100Canvas.h"

T100Canvas::T100Canvas() :
    T100Window()
{
    //ctor
}

T100Canvas::T100Canvas(T100Win32Application* app, T100Window* parent) :
    T100Window(app, parent)
{
    //ctor
}

T100Canvas::~T100Canvas()
{
    //dtor
}

T100VOID T100Canvas::Create(T100Win32Application* app, T100Window* parent, T100WSTRING label, T100WindowStyle* style)
{
    T100Window::Create(app, parent, style);
}
