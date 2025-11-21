#include "T100PainterApplication.h"

T100PainterApplication::T100PainterApplication() :
    T100Win32Application(),
    m_painter()
{
    //ctor
}

T100PainterApplication::~T100PainterApplication()
{
    //dtor
}

T100VOID T100PainterApplication::Create()
{
    m_painter.Create(this);
    T100Win32Application::Create();
}
