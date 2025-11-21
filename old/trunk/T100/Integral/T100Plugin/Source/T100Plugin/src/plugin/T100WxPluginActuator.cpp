#include "T100WxPluginActuator.h"

#include <windows.h>

T100WxPluginActuator::T100WxPluginActuator() :
    T100PluginActuator(),
    wxEvtHandler()
{
    //ctor
}

T100WxPluginActuator::~T100WxPluginActuator()
{
    //dtor
}

T100VOID T100WxPluginActuator::OnFileOpen(wxCommandEvent& event)
{
    MessageBoxA(0, "Open", "DLL Message", MB_OK | MB_ICONINFORMATION);
}

T100VOID T100WxPluginActuator::OnFileQuit(wxCommandEvent& event)
{
    MessageBoxA(0, "Quit", "DLL Message", MB_OK | MB_ICONINFORMATION);
}
