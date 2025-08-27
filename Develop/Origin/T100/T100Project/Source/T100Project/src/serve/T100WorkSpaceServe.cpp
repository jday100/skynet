#include "T100WorkSpaceServe.h"

#include "T100Folder.h"
#include "T100WorkSpaceFile.h"
#include "T100ProjectConfig.h"

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
    m_opened    = T100FALSE;
}

T100VOID T100WorkSpaceServe::uninit()
{
}

T100BOOL T100WorkSpaceServe::CreateWorkSpace(T100WorkSpaceInfo* info)
{
    if(!info){
        return T100FALSE;
    }

    return T100TRUE;
}

T100BOOL T100WorkSpaceServe::OpenWorkSpace(T100WorkSpaceInfo* info)
{
    if(!info){
        return T100FALSE;
    }

    return T100TRUE;
}

T100BOOL T100WorkSpaceServe::CreateWorkSpaceFile(T100WorkSpaceInfo* info)
{
    if(!info){
        return T100FALSE;
    }

    T100WSTRING         filename;
    T100WxFolderInfo    folder;

    folder.SetPath(info->GetPath());

    filename    = GetFileName(folder);

    T100WorkSpaceFile       file(filename);

    if(file.IsExists()){
        return T100FALSE;
    }

    file.Save(info);

    return T100TRUE;
}

T100BOOL T100WorkSpaceServe::OpenWorkSpaceFile(T100WorkSpaceInfo* info)
{
    if(!info){
        return T100FALSE;
    }

    return T100TRUE;
}

T100BOOL T100WorkSpaceServe::CheckWorkSpaceFolder(const T100WxFolderInfo& info)
{
    T100Folder          folder(info.GetPath());

    return folder.IsExists();
}

T100BOOL T100WorkSpaceServe::CheckWorkSpaceFile(const T100WxFolderInfo& info)
{
    T100WSTRING         filename;

    filename    = GetFileName(info);

    T100WorkSpaceFile   file(filename);

    return file.IsExists();
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

    m_info      = T100NEW T100WorkSpaceInfo();

    m_info->SetLabel(info.GetLabel());
    m_info->SetPath(info.GetPath());
    m_info->SetFileName(filename);

    if(!WorkSpaceOpen(m_info)){
        return T100FALSE;
    }

    return T100TRUE;
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

T100BOOL T100WorkSpaceServe::Close()
{
    return T100FALSE;
}

T100BOOL T100WorkSpaceServe::Save()
{

}

T100VOID T100WorkSpaceServe::Clear()
{

}

T100VOID T100WorkSpaceServe::Open(T100WorkSpaceInfo* info)
{
    WorkSpaceOpen(info);
}

T100BOOL T100WorkSpaceServe::Close(T100WorkSpaceInfo*)
{

}

T100VOID T100WorkSpaceServe::Save(T100WorkSpaceInfo*)
{

}

T100VOID T100WorkSpaceServe::SaveAs(T100WorkSpaceInfo*)
{

}

T100BOOL T100WorkSpaceServe::WorkSpaceOpen(T100WorkSpaceInfo* info)
{
    if(!info){
        return T100FALSE;
    }

    T100FILE_INFO_VECTOR&       files       = info->GetFiles();
    T100FOLDER_INFO_VECTOR&     folders     = info->GetFolders();
    T100PROJECT_INFO_VECTOR&    projects    = info->GetProjects();

    T100WSTRING_VECTOR          fileNames;
    T100WSTRING_VECTOR          folderNames;

    T100Folder          folder(info->GetPath());

    if(!folder.IsExists()){
        return T100FALSE;
    }

    folder.List(folderNames, fileNames);

    for(const T100WSTRING& item : folderNames){
        T100WxFolderInfo        thisFolder;

        thisFolder.SetLabel(item);
        T100WSTRING     path    = m_info->GetPath() + L"/" + item;
        thisFolder.SetPath(path);

        if(m_projectServe.Check(&thisFolder)){
            T100ProjectInfo*    thisProject     = T100NEW T100ProjectInfo();

            thisProject->SetLabel(item);
            thisProject->SetPath(path);
            thisProject->SetFileName(m_projectServe.GetProjectLogic().GetFileName(thisFolder));

            projects.push_back(thisProject);
        }else{
            T100FolderInfo*     thisInfo        = T100NEW T100FolderInfo();

            thisInfo->SetLabel(item);
            thisInfo->SetPath(path);

            folders.push_back(thisInfo);
        }
    }

    for(const T100WSTRING& item : fileNames){
        T100FileInfo*       thisFile        = T100NEW T100FileInfo();

        thisFile->SetFileName(item);

        files.push_back(thisFile);
    }

    return T100TRUE;
}

T100BOOL T100WorkSpaceServe::WorkSpaceClose()
{
    return T100FALSE;
}

T100VOID T100WorkSpaceServe::Build()
{
    m_projectServe.GetProjectLogic().Build();
}

T100WSTRING T100WorkSpaceServe::GetFileName(const T100WxFolderInfo& info)
{
    T100WSTRING         filename;

    filename    = info.GetPath() + L"/" + T100ProjectConfig::T100PROJECT_WORKSPACE_FILENAME;

    return filename;
}
