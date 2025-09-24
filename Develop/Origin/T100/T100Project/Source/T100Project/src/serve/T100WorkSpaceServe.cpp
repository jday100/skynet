#include "T100WorkSpaceServe.h"

#include "T100PathTools.h"
#include "T100Folder.h"
#include "T100WorkSpaceFile.h"
#include "T100ProjectConfig.h"

T100WorkSpaceServe::T100WorkSpaceServe() :
    m_serveFile(),
    m_serveFolder(),
    m_serveProject()
{
    //ctor
    m_opened        = T100FALSE;
}

T100WorkSpaceServe::~T100WorkSpaceServe()
{
    //dtor
}

T100FileServe& T100WorkSpaceServe::GetFileServe()
{
    return m_serveFile;
}

T100FolderServe& T100WorkSpaceServe::GetFolderServe()
{
    return m_serveFolder;
}

T100ProjectServe& T100WorkSpaceServe::GetProjectServe()
{
    return m_serveProject;
}

T100VOID T100WorkSpaceServe::SetOpened(T100BOOL value)
{
    m_opened        = value;
}

T100BOOL T100WorkSpaceServe::IsOpened()
{
    return m_opened;
}

T100WSTRING T100WorkSpaceServe::GetFileName(const T100WSTRING& path)
{
    T100WSTRING         result;

    if(path.empty()){
        return result;
    }

    result  = path + T100ProjectConfig::T100PROJECT_STORAGE_SEPARATOR + T100ProjectConfig::T100PROJECT_WORKSPACE_CONFIG_FILENAME;

    return result;
}

T100BOOL T100WorkSpaceServe::Create()
{
    m_workspace     = T100NEW T100WorkSpaceInfo();
    return T100TRUE;
}

T100WorkSpaceInfo* T100WorkSpaceServe::GetWorkSpaceInfo()
{
    return m_workspace;
}

T100BOOL T100WorkSpaceServe::CheckWorkSpaceFolder(const T100WSTRING& path)
{
    T100Folder          folder(path);

    return folder.IsExists();
}

T100BOOL T100WorkSpaceServe::CheckWorkSpaceFile(T100WxFolderInfo* info)
{
    if(!info){
        return T100FALSE;
    }

    T100WSTRING         filename;

    filename    = GetFileName(info->GetPath());

    T100WorkSpaceFile       file(filename);

    return file.IsExists();
}

T100BOOL T100WorkSpaceServe::CreateWorkSpace(T100WorkSpaceInfo* info)
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

    T100WSTRING             filename;

    filename    = GetFileName(info->GetPath());

    T100WorkSpaceFile       file(filename);

    if(file.IsExists()){
        return T100FALSE;
    }

    return file.Save(info);
}

T100BOOL T100WorkSpaceServe::OpenWorkSpaceFile(T100WorkSpaceInfo* info)
{
    if(!info){
        return T100FALSE;
    }

    T100WSTRING         filename;

    filename    = GetFileName(info->GetPath());

    T100WorkSpaceFile       file(filename);

    if(!file.IsExists()){
        return T100FALSE;
    }

    if(!file.Load(info)){
        return T100FALSE;
    }

    return T100TRUE;
}

T100BOOL T100WorkSpaceServe::OpenWorkSpace(T100WorkSpaceInfo* info)
{
    if(!info){
        return T100FALSE;
    }

    info->SetExecutePath(T100PathTools::GetCwd());

    T100FILE_INFO_VECTOR&           files       = info->GetFiles();
    T100FOLDER_INFO_VECTOR&         folders     = info->GetSubFolders();
    T100PROJECT_INFO_VECTOR&        projects    = info->GetProjects();

    T100WSTRING_VECTOR              fileNames;
    T100WSTRING_VECTOR              folderNames;

    T100Folder          folder(info->GetPath());

    if(!folder.IsExists()){
        return T100FALSE;
    }

    folder.List(folderNames, fileNames);

    for(const T100WSTRING& item : folderNames){
            T100WSTRING         thisPath;
            T100WxFolderInfo    thisFolder;

            thisFolder.SetLabel(item);
            thisPath    = m_workspace->GetPath() + T100ProjectConfig::T100PROJECT_STORAGE_SEPARATOR + item;
            thisFolder.SetPath(thisPath);

            if(m_serveProject.Check(&thisFolder)){

                T100ProjectInfo*    thisProject     = T100NEW T100ProjectInfo();

                thisProject->SetLabel(item);
                thisProject->SetPath(thisPath);
                thisProject->SetFileName(m_serveProject.GetFileName(thisPath));
                thisProject->SetBuildFileName(item + L".exe");

                projects.push_back(thisProject);
            }else{
                T100FolderInfo*     thisInfo        = T100NEW T100FolderInfo();

                thisInfo->SetLabel(item);
                thisInfo->SetPath(thisPath);

                folders.push_back(thisInfo);
            }
    }

    return T100TRUE;

    for(const T100WSTRING& item : fileNames){
        if(item == T100ProjectConfig::T100PROJECT_WORKSPACE_CONFIG_FILENAME){

        }else{
            T100WSTRING         thisPath        = info->GetPath() + T100ProjectConfig::T100PROJECT_STORAGE_SEPARATOR + item;
            T100FileInfo*       thisFile        = T100NEW T100FileInfo();

            thisFile->SetLabel(item);
            thisFile->SetFileName(item);
            thisFile->SetPath(thisPath);

            files.push_back(thisFile);
        }
    }
    return T100TRUE;
}

T100BOOL T100WorkSpaceServe::CloseWorkSpace()
{
    if(m_opened && m_workspace){

    }else{
        return T100FALSE;
    }

    if(!m_serveFile.Clear()){
        return T100FALSE;
    }

    if(!m_serveFolder.Clear()){
        return T100FALSE;
    }

    if(!m_serveProject.Clear()){

    }

    T100SAFE_DELETE(m_workspace);
    m_opened    = T100FALSE;
    return T100TRUE;
}
