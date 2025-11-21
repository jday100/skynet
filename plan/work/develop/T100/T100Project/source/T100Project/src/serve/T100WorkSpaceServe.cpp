#include "T100WorkSpaceServe.h"

#include "T100Folder.h"
#include "T100WorkSpaceFile.h"

T100WorkSpaceServe::T100WorkSpaceServe() :
    m_projectServe()
{
    //ctor
    init();
}

T100WorkSpaceServe::~T100WorkSpaceServe()
{
    //dtor
    uninit();
}

T100VOID T100WorkSpaceServe::init()
{
}

T100VOID T100WorkSpaceServe::uninit()
{
}

T100ProjectServe* T100WorkSpaceServe::GetProjectServe()
{
    return &m_projectServe;
}

T100VOID T100WorkSpaceServe::GetProjects(T100PROJECT_INFO_VECTOR& projects)
{
    m_projectServe.GetProjects(projects);
}

T100WorkSpaceInfo* T100WorkSpaceServe::GetWorkSpaceInfo()
{
    return m_info;
}

T100VOID T100WorkSpaceServe::GetFolderInfo(T100WxFolderInfo& info)
{
    info.SetLabel(m_info->GetLabel());
    info.SetPath(m_info->GetPath());
}

T100BOOL T100WorkSpaceServe::IsOpened()
{
    return m_opened;
}

T100BOOL T100WorkSpaceServe::New(const T100WxFolderInfo& info)
{
    T100WSTRING         filename;
    T100Folder          folder(info.GetPath());

    filename    = GetFileName(info);

    T100WorkSpaceFile   file(filename);

    if(!folder.IsExists()){
        return T100FALSE;
    }

    if(file.IsExists()){
        return T100FALSE;
    }

    file.Save();
    return T100TRUE;
}

T100BOOL T100WorkSpaceServe::Open(const T100WxFolderInfo& info)
{
    T100Folder          folder(info.GetPath());

    if(!folder.IsExists()){
        return T100FALSE;
    }

    T100WSTRING         filename;

    filename    = GetFileName(info);

    T100WorkSpaceFile       file(filename);

    if(!file.IsExists()){
        return T100FALSE;
    }

    if(!file.Load()){
        return T100FALSE;
    }

    T100WSTRING_VECTOR      folders;

    folder.GetAllSubFolders(folders);

    m_info      = T100NEW T100WorkSpaceInfo();

    m_info->SetLabel(info.GetLabel());
    m_info->SetPath(info.GetPath());
    m_info->SetFileName(filename);

    if(!m_projectServe.Open(folders, m_info->GetProjects())){
        return T100FALSE;
    }

    return T100TRUE;
}

T100VOID T100WorkSpaceServe::Close()
{

}

T100BOOL T100WorkSpaceServe::Save()
{

}

T100VOID T100WorkSpaceServe::Clear()
{

}

T100VOID T100WorkSpaceServe::Create(T100WorkSpaceInfo*)
{

}

T100VOID T100WorkSpaceServe::Open(T100WorkSpaceInfo* info)
{
    OpenWorkSpace(info);
}

T100VOID T100WorkSpaceServe::Close(T100WorkSpaceInfo*)
{

}

T100VOID T100WorkSpaceServe::Save(T100WorkSpaceInfo*)
{

}

T100VOID T100WorkSpaceServe::SaveAs(T100WorkSpaceInfo*)
{

}

T100VOID T100WorkSpaceServe::OpenWorkSpace(T100WorkSpaceInfo* info)
{

}

T100VOID T100WorkSpaceServe::Build()
{

}

T100WSTRING T100WorkSpaceServe::GetFileName(const T100WxFolderInfo& info)
{
    T100WSTRING         filename;

    filename    = info.GetPath() + L"/" + info.GetLabel() + L".ws";

    return filename;
}
