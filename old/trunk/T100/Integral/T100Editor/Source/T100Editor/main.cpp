#include "main.h"

#include "T100MainMain.h"
#include "T100PluginEditorActuator.h"

void DLL_EXPORT SignIn(void* value)
{
    if(!value){
        return;
    }

    T100MainFrame*      frame   = (T100MainFrame*)value;

    if(m_actuator){

    }else{
        m_actuator  = T100NEW T100PluginEditorActuator(*frame);
        m_actuator->SetFrame(frame);

        m_actuator->SignIn();
    }
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
