#include "T100Win32Capture.h"


T100Win32Capture::T100Win32Capture() :
    T100Class()
{
    //ctor
}

T100Win32Capture::~T100Win32Capture()
{
    //dtor
}

HWND T100Win32Capture::Find(T100WSTRING label)
{
    return FindWindow(T100NULL, label.c_str());
}

T100VOID T100Win32Capture::Launch(T100WSTRING value)
{
    HINSTANCE   result  = ShellExecute(T100NULL, L"open", value.c_str(), T100NULL, T100NULL, SW_SHOW);
}
