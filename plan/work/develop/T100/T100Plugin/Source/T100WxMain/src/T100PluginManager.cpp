#include "T100PluginManager.h"

#include <libloaderapi.h>

typedef int (*INIT)(wxFrame*);

T100PluginManager::T100PluginManager()
{
    //ctor
}

T100PluginManager::~T100PluginManager()
{
    //dtor
}

void T100PluginManager::Start(wxFrame* frame)
{
    HMODULE     module;

    module      = LoadLibrary("T100WxPlugin.dll");

    if(!module){
        return;
    }

    FARPROC     proc    = GetProcAddress(module, "Init");

    if(!proc){
        return;
    }

    INIT    init    = (INIT)proc;

    int     result  = init(frame);

}

void T100PluginManager::Stop()
{

}
