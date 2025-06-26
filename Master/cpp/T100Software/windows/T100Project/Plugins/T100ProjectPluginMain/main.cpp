#include "main.h"

#include "T100ProjectApplication.h"
#include "skeletal/T100ProjectInvoking.h"

void ModuleInit(T100Win32Application* application)
{
    g_mainMenu      = T100NEW T100ProjectMainMenu(application);

    g_mainMenu->Create();

    //MessageBoxW(0, L"ModuleInit", L"DLL Message", MB_OK | MB_ICONINFORMATION);
}

T100MenuBar* DLL_EXPORT Main_GetMainMenuBar()
{
    return g_mainMenu->GetMenuBar();
}

// a sample exported function
void DLL_EXPORT SomeFunction(const LPCSTR sometext)
{
    //MessageBoxA(0, sometext, "DLL Message", MB_OK | MB_ICONINFORMATION);
}

void DLL_EXPORT PluginInit(T100ProjectApplication* application)
{
    //MessageBoxW(0, L"PluginInit", L"DLL Message", MB_OK | MB_ICONINFORMATION);

    T100ProjectInvoking::Create(application);

    ModuleInit(application);
}

void ViewResize(T100WindowEvent& event)
{
    PostQuitMessage(0);
}

void DLL_EXPORT MenuSignIn()
{

}

void DLL_EXPORT MenuSignOut()
{

}

void DLL_EXPORT ViewSignIn(T100VOID* value)
{
    T100ProjectApplication*     application;

    application = (T100ProjectApplication*)value;

    if(!application){
        return;
    }

    T100VOID*   call;

    call    = (T100VOID*)&ViewResize;

    application->GetSkeletal().GetExtendedManager().Connect(L"T100Project.View.Main.Frame.Resize", call);
}

void DLL_EXPORT ViewSignOut()
{

}

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
