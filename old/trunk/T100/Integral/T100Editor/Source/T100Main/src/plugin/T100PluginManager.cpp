#include "T100PluginManager.h"

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
                if(SignIn(library)){
                    continue;
                }
            }
        }

        T100SAFE_DELETE(library)
    }
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
