#include "T100ProjectManager.h"

T100ProjectManager::T100ProjectManager()
{
    //ctor
}

T100ProjectManager::~T100ProjectManager()
{
    //dtor
}

T100PROJECT_VESSEL& T100ProjectManager::GetProjects()
{
    return m_projects;
}

T100VOID T100ProjectManager::Create(T100UINT type, T100ProjectInfo& info)
{
    T100WSTRING         path        = L"../../workspace/project";

    info.GetProjectData().SetLabel(path);
}
