#include "main.h"

#include <wx/menu.h>
#include "T100MainMain.h"
#include "T100WxPluginActuator.h"

static T100WxPluginActuator*       m_actuator      = T100NULL;


void __declspec(dllexport) Init(T100MainFrame* frame)
{
    if(m_actuator){

    }else{
        m_actuator  = T100NEW T100WxPluginActuator();
    }

    frame->Maximize();

    T100INT     fileOpenID      = wxNewId();

    wxMenuItem*     fileOpen        = T100NEW wxMenuItem(T100NULL, fileOpenID, L"Open");

    frame->GetMenuBar()->GetMenu(0)->Insert(0, fileOpen);
    frame->GetMenuBar()->GetMenu(0)->InsertSeparator(1);

    frame->Connect(fileOpenID,              wxEVT_COMMAND_MENU_SELECTED,    (wxObjectEventFunction)&T100WxPluginActuator::OnFileOpen);
    frame->Disconnect(frame->idMenuQuit,    wxEVT_COMMAND_MENU_SELECTED);
    frame->Connect(frame->idMenuQuit,       wxEVT_COMMAND_MENU_SELECTED,    (wxObjectEventFunction)&T100WxPluginActuator::OnFileQuit, T100NULL, m_actuator);

}

/*
// a sample exported function
void DLL_EXPORT SomeFunction(const LPCSTR sometext)
{
    MessageBoxA(0, sometext, "DLL Message", MB_OK | MB_ICONINFORMATION);
}
*/
/*
extern "C" DLL_EXPORT BOOL APIENTRY DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved)
{
    switch (fdwReason)
    {
        case DLL_PROCESS_ATTACH:
            // attach to process
            // return FALSE to fail DLL load
            break;

        case DLL_PROCESS_DETACH:
            // detach from process
            break;

        case DLL_THREAD_ATTACH:
            // attach to thread
            break;

        case DLL_THREAD_DETACH:
            // detach from thread
            break;
    }
    return TRUE; // succesful
}
*/
