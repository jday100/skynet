#include "T100PluginManager.h"

#include <libloaderapi.h>
#include "T100Folder.h"

T100PluginManager::T100PluginManager()
{
    //ctor
}

T100PluginManager::~T100PluginManager()
{
    //dtor
}

T100VOID T100PluginManager::Start(T100MainFrame* frame)
{
    m_frame     = frame;

    T100Folder      folder(L"./plugins");

    if(folder.IsExists()){

    }else{
        return;
    }

    T100WSTRING_VECTOR      files;

    folder.GetAllFiles(files, L"*.dll");

    for(T100WSTRING& file : files){
        T100WSTRING path    = L"./plugins/" + file;
        if(Load(path)){

        }else{

        }
    }
}

T100VOID T100PluginManager::Stop()
{

}

T100BOOL T100PluginManager::Load(T100WSTRING& path)
{
    HMODULE     module;

    module  = LoadLibraryW(path.c_str());

    FARPROC     proc    = GetProcAddress(module, "Init");

    typedef T100VOID(*FUNC)(T100MainFrame*);

    if(proc){
        FUNC    func    = (FUNC)proc;

        func(m_frame);
    }
}
