#include "T100ProjectLogic.h"

#include "T100Shell.h"
#include "T100Folder.h"
#include "T100ProjectFile.h"
#include "T100ProjectConfig.h"
#include "T100WorkSpaceInfo.h"

T100ProjectLogic::T100ProjectLogic()
{
    //ctor
    init();
}

T100ProjectLogic::T100ProjectLogic(T100ProjectInfo* info) :
    m_project(info)
{
    //ctor
    uninit();
}

T100ProjectLogic::~T100ProjectLogic()
{
    //dtor
}

T100VOID T100ProjectLogic::init()
{
    m_file      = T100NEW T100FileLogic();
    m_folder    = T100NEW T100FolderLogic();
}

T100VOID T100ProjectLogic::uninit()
{
    T100SAFE_DELETE(m_file);
    T100SAFE_DELETE(m_folder);
}

T100BOOL T100ProjectLogic::NewNew(const T100WxFolderInfo& info, T100WorkSpaceInfo* workspace)
{
    T100WSTRING         name;
    T100WSTRING         filename;

    Execute(info, workspace);

    return T100TRUE;

    name    = GetFolderName(info);

    T100Folder          folder(name);

    if(folder.IsExists()){
        return T100FALSE;
    }

    if(!folder.Create()){
        return T100FALSE;
    }

    filename    = GetFileName(info);

    T100ProjectFile     file(filename);

    if(file.IsExists()){
        return T100FALSE;
    }

    if(!file.Create()){
        return T100FALSE;
    }

    T100ProjectInfo*    project     = T100NULL;

    project     = T100NEW T100ProjectInfo();

    project->SetLabel(info.GetLabel());
    project->SetPath(name);
    project->SetFileName(filename);

    m_project   = project;

    return T100TRUE;
}

T100BOOL T100ProjectLogic::Execute(const T100WxFolderInfo& info, T100WorkSpaceInfo* workspace)
{
    T100WSTRING         name;
    T100WSTRING         filename;

    name    = GetFolderName(info);

    T100Shell       shell;
    T100WSTRING     command;

    command = L"C:/zmsys2/msys2/mingw64/bin/python3 C:/zgit/skynet/Develop/Origin/T100/T100Project/Source/T100Project/scripts/project/Project.py C:/vm/Hello";

    shell.Run(command);
}

















T100ProjectInfo* T100ProjectLogic::GetProjectInfo()
{
    return m_project;
}

T100BOOL T100ProjectLogic::Check(T100WxFolderInfo* info)
{
    if(!info){
        return T100FALSE;
    }

    if(!m_folder->IsExists(info->GetPath())){
        return T100FALSE;
    }

    T100WSTRING             filename;

    filename    = GetFileName(*info);

    T100ProjectFile         projectFile(filename);

    if(!m_file->IsExists(filename)){
        return T100FALSE;
    }

    if(!projectFile.Check(filename)){
        return T100FALSE;
    }
    return T100TRUE;
}

T100BOOL T100ProjectLogic::New(const T100WxFolderInfo& info)
{
    T100WSTRING         name;
    T100WSTRING         filename;

    name    = GetFolderName(info);

    T100Folder          folder(name);

    if(folder.IsExists()){
        return T100FALSE;
    }

    if(!folder.Create()){
        return T100FALSE;
    }

    filename    = GetFileName(info);

    T100ProjectFile     file(filename);

    if(file.IsExists()){
        return T100FALSE;
    }

    if(!file.Create()){
        return T100FALSE;
    }

    T100ProjectInfo*    project     = T100NULL;

    project     = T100NEW T100ProjectInfo();

    project->SetLabel(info.GetLabel());
    project->SetPath(name);
    project->SetFileName(filename);

    m_project   = project;

    return T100TRUE;
}

T100BOOL T100ProjectLogic::Open(const T100WSTRING& value)
{

}

T100BOOL T100ProjectLogic::Open(const T100WSTRING& path, T100ProjectInfo* info)
{
    T100Folder      folder(path);

    if(!folder.IsExists()){
        return T100FALSE;
    }

    T100FILE_INFO_VECTOR&       files       = info->GetFiles();
    T100FOLDER_INFO_VECTOR&     folders     = info->GetSubFolders();

    T100WSTRING_VECTOR          fileNames;
    T100WSTRING_VECTOR          folderNames;

    folder.List(folderNames, fileNames);

    for(const T100WSTRING& item : folderNames){
        T100WxFolderInfo        thisFolder;

        thisFolder.SetLabel(item);
        T100WSTRING     thisPath    = path + L"/" + item;
        thisFolder.SetPath(thisPath);

        T100FolderInfo*     thisInfo        = T100NEW T100FolderInfo();

        thisInfo->SetLabel(item);
        thisInfo->SetPath(thisPath);

        folders.push_back(thisInfo);
    }

    for(const T100WSTRING& item : fileNames){
        T100WSTRING         thisPath        = path + L"/" + item;
        T100FileInfo*       thisFile        = T100NEW T100FileInfo();

        thisFile->SetFileName(item);
        thisFile->SetPath(thisPath);

        files.push_back(thisFile);
    }

    m_current   = info;

    return T100TRUE;
}

T100VOID T100ProjectLogic::Build()
{
    if(!m_current){
        return;
    }

    T100Shell       shell;
    T100WSTRING     command;

    //command     = L"python3 " + GetBuildName(m_current) + L";pause";

    command     = L"C:/zmsys2/msys2/mingw64/bin/python3 " + GetBuildName(m_current);

    shell.Run(command);
}

T100WSTRING T100ProjectLogic::GetFileName(const T100WxFolderInfo& info)
{
    return info.GetPath() + L"/" + T100ProjectConfig::T100PROJECT_PROJECT_FILENAME;
}

T100WSTRING T100ProjectLogic::GetFolderName(const T100WxFolderInfo& info)
{
    return info.GetPath();
}

T100WSTRING T100ProjectLogic::GetBuildName(const T100ProjectInfo* info)
{
    return info->GetPath() + L"/" + L"Make.py";
}
