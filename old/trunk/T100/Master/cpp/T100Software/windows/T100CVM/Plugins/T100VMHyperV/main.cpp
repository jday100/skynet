#include "main.h"

// a sample exported function
void DLL_EXPORT SomeFunction(const LPCSTR sometext)
{
    MessageBoxA(0, sometext, "DLL Message", MB_OK | MB_ICONINFORMATION);
}

void DLL_EXPORT VM_Start()
{
    if(!g_win){
        g_win   = T100NEW T100VMWin();
    }

    g_win->Start();

    return;
    if(!g_vm){
        g_vm    = T100NEW T100VMHyperV();
    }

    g_vm->Start();
}

void DLL_EXPORT VM_Stop()
{
    g_win->Stop();

    T100SAFE_DELETE(g_win);

    return;
    g_vm->Stop();

    T100SAFE_DELETE(g_vm);
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
