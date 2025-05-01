#include "T100FrameBase.h"

T100FrameBase::T100FrameBase() :
    T100OwnedWindow()
{
    //ctor
}

T100FrameBase::~T100FrameBase()
{
    //dtor
}

T100VOID T100FrameBase::Maximize()
{
    ShowWindow(m_hwnd, SW_MAXIMIZE);
}

T100VOID T100FrameBase::Minimize()
{
    ShowWindow(m_hwnd, SW_MINIMIZE);
}

T100VOID T100FrameBase::RestoreSize()
{
    ShowWindow(m_hwnd, SW_RESTORE);
}
