#include "plugin\T100PluginManager.h"

#include "T100WxMainMain.h"
#include "library\storage\folder\T100Folder.h"


T100PluginManager::T100PluginManager()
{
    //ctor
}

T100PluginManager::~T100PluginManager()
{
    //dtor
}

T100VOID T100PluginManager::Start(T100VOID* value)
{
    m_handler       = value;

    Load();
}

T100VOID T100PluginManager::Stop()
{

}

T100BOOL T100PluginManager::Load()
{
    T100Folder      folder(L"./plugins");

    if(folder.IsExists()){

    }else{
        return T100FALSE;
    }

    T100WSTRING_VECTOR      files;

    folder.GetAllFiles(files, L"*.dll");

    for(T100WSTRING& file : files){
        T100WSTRING     path    = L"./plugins/" + file;

        T100Library*    library     = T100NEW T100Library(path);

        if(library->IsExists()){
            if(library->Load()){
                if(Launch(library)){
                    continue;
                }
            }
        }

        T100SAFE_DELETE(library)
    }
    return T100TRUE;
}

T100BOOL T100PluginManager::Launch(T100Library* library)
{
    if(!library){
        return T100FALSE;
    }

    T100PLUGIN_LAUNCH       launch      = (T100PLUGIN_LAUNCH)library->GetProcedure("Launch");

    if(!launch){
        return T100FALSE;
    }

    T100Plugin*     plugin      = launch();

    if(!plugin){
        return T100FALSE;
    }

    T100WxMainFrame*    frame   = (T100WxMainFrame*)m_handler;

    if(!frame){
        return T100FALSE;
    }

    frame->Disconnect(frame->GetQuitID(),   wxEVT_COMMAND_MENU_SELECTED,        (wxObjectEventFunction)&T100WxMainFrame::OnQuit);

    plugin->Create(m_handler);

    return T100TRUE;
}

T100BOOL T100PluginManager::SignIn(T100Library* library)
{
    if(!library){
        return T100FALSE;
    }

    T100PLUGIN_SIGNIN       signin      = (T100PLUGIN_SIGNIN)library->GetProcedure("SignIn");

    if(!signin){
        return T100FALSE;
    }

    signin(m_handler);

    return T100TRUE;
}

T100BOOL T100PluginManager::SignOut(T100Library* library)
{
    if(!library){
        return T100FALSE;
    }
    return T100TRUE;
}
