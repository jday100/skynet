#include "T100PluginProjectStore.h"

#include "T100Folder.h"
#include "T100Project.h"

T100PluginProjectStore::T100PluginProjectStore()
{
    //ctor
}

T100PluginProjectStore::~T100PluginProjectStore()
{
    //dtor
}

T100VOID T100PluginProjectStore::SetPath(const T100WSTRING& path)
{
    m_path      = path;
}

const T100WSTRING& T100PluginProjectStore::GetPath()
{
    return m_path;
}

T100VOID T100PluginProjectStore::Load(T100PROJECT_VESSEL& result)
{
    T100Folder              folder(m_path);
    T100WSTRING_VECTOR      folders;

    folder.GetAllSubFolders(folders);

    for(T100WSTRING& name : folders){
        T100Project*    project     = T100NEW T100Project(name);
        if(!project){
            return;
        }
        result.Append(name, project);
    }
}

T100VOID T100PluginProjectStore::Create(T100ProjectInfo& info)
{
    const T100Project&      data        = info.GetProjectData();

    CreateProject(data);
}

T100VOID T100PluginProjectStore::CreateProject(const T100Project& data)
{
    T100Folder          folder(L"../../workspace/project");

    if(!folder.IsExists()){
        folder.Create();
    }
}
