#include "T100ProjectLogic.h"

#include "T100DebugTools.h"
#include <wx/utils.h>
#include "T100Shell.h"
#include "T100Folder.h"
#include "T100ProjectFile.h"
#include "T100ProjectConfig.h"
#include "T100ModuleInfo.h"
#include "T100WorkSpaceInfo.h"

T100ProjectLogic::T100ProjectLogic()
{
    //ctor
    init();
}

T100ProjectLogic::T100ProjectLogic(T100ProjectInfo* info) :
    m_current(info)
{
    //ctor
    init();
}

T100ProjectLogic::~T100ProjectLogic()
{
    //dtor
    uninit();
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

T100ProjectInfo* T100ProjectLogic::GetCurrent()
{
    return m_current;
}

T100WSTRING T100ProjectLogic::GetFileName(const T100WxFolderInfo& info)
{
    return info.GetPath() + T100ProjectConfig::T100PROJECT_STORAGE_SEPARATOR + T100ProjectConfig::T100PROJECT_PROJECT_FILENAME;
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

T100BOOL T100ProjectLogic::Create(const T100WxFolderInfo& info, T100WorkSpaceInfo* workspace)
{
    if(!workspace){
        return T100FALSE;
    }

    T100WSTRING         name;
    T100WSTRING         filename;

    wxBell();

    T100ProjectInfo*    project     = T100NEW T100ProjectInfo();

    project->SetLabel(info.GetLabel());
    project->SetPath(info.GetPath());

    Execute(workspace, project);

    m_current   = project;

    return T100TRUE;
}

T100BOOL T100ProjectLogic::Remove(T100ProjectInfo* info)
{

}

T100BOOL T100ProjectLogic::Open(const T100WSTRING& path, T100ProjectInfo* info)
{
    T100DebugTools::Print(L"ProjectLogic::Open...");
    if(!info){
        return T100FALSE;
    }

    if(info->IsOpened()){
        return T100FALSE;
    }

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
        if(item == info->GetBuildPath()){
            continue;
        }

        T100WxFolderInfo        thisFolder;

        thisFolder.SetLabel(item);
        T100WSTRING     thisPath    = path + T100ProjectConfig::T100PROJECT_STORAGE_SEPARATOR + item;
        thisFolder.SetPath(thisPath);

        T100FolderInfo*     thisInfo        = T100NEW T100FolderInfo();

        thisInfo->SetLabel(item);
        thisInfo->SetPath(thisPath);

        folders.push_back(thisInfo);
    }

    for(const T100WSTRING& item : fileNames){
        if(item == T100ProjectConfig::T100PROJECT_PROJECT_FILENAME){

        }else{
            T100WSTRING         thisPath        = path + T100ProjectConfig::T100PROJECT_STORAGE_SEPARATOR + item;
            T100FileInfo*       thisFile        = T100NEW T100FileInfo();

            thisFile->SetLabel(item);
            thisFile->SetFileName(item);
            thisFile->SetPath(thisPath);

            files.push_back(thisFile);
        }
    }

    info->SetOpened(T100TRUE);
    m_current   = info;

    return T100TRUE;
}

T100BOOL T100ProjectLogic::Close(T100ProjectInfo*)
{

}

T100BOOL T100ProjectLogic::Rename(T100ProjectInfo*)
{

}

T100BOOL T100ProjectLogic::Clean(T100ProjectInfo*)
{

}

T100BOOL T100ProjectLogic::Run(T100WorkSpaceInfo* workspace, T100ProjectInfo* project)
{
    if(workspace && m_current){

    }else{
        return T100FALSE;
    }

    wxBell();

    T100Shell       shell;
    T100WSTRING     command;

    command = m_current->GetPath() + T100ProjectConfig::T100PROJECT_STORAGE_SEPARATOR + L"build\\main.exe";

    shell.Run(command);
}

T100BOOL T100ProjectLogic::Build(T100WorkSpaceInfo*, T100ProjectInfo*)
{
    if(!m_current){
        return;
    }

    wxBell();

    T100Shell       shell;
    T100WSTRING     command;

    //command     = L"python3 " + GetBuildName(m_current) + L";pause";

    command     = L"C:/zmsys2/msys2/mingw64/bin/python3 " + GetBuildName(m_current);

    command     = L"C:/zmsys2/msys2/mingw64/bin/python3 C:/vm/Hello/Make.py build";

    shell.Run(command);

    return T100TRUE;
}

T100BOOL T100ProjectLogic::Rebuild(T100WorkSpaceInfo*, T100ProjectInfo*)
{

}

T100BOOL T100ProjectLogic::CreateModule(T100WorkSpaceInfo* workspace, T100ModuleInfo* info)
{
    if(workspace && m_current && info){

    }else{
        return T100FALSE;
    }

    T100Shell       shell;
    T100WSTRING     command;
    T100WSTRING     args;
    T100WSTRING     line;

    command     = workspace->GetPythonFile() + L" " +
                    workspace->GetExecutePath() + L"\\scripts\\project\\Module.py";

    args        = m_current->GetPath() + L" " +
                    m_current->GetCodePath() + L" " +
                    m_current->GetIncludePath() + L" " +
                    m_current->GetSourcePath() + L" " +
                    info->GetLabel() + L" " +
                    info->GetLabel() + L".h" + L" " +
                    info->GetLabel() + L".cpp";

    line    = command + L" " + args;

    shell.Print(line);

    shell.Run(line);

    return T100TRUE;
}

T100BOOL T100ProjectLogic::Execute(T100WorkSpaceInfo* workspace, T100ProjectInfo* project)
{
    if(workspace && project){

    }else{
        return T100FALSE;
    }

    T100Shell       shell;
    T100WSTRING     command;
    T100WSTRING     args;
    T100WSTRING     line;

    command = workspace->GetPythonFile() + L" " + workspace->GetExecutePath() + L"\\scripts\\project\\ProjectCreate.py";
    args    = project->GetPath() + L" " +
                workspace->GetExecutePath() + L" " +
                workspace->GetPythonFile() + L" " +
                project->GetBuildPath() + L" " +
                project->GetCodePath() + L" " +
                project->GetIncludePath() + L" " +
                project->GetSourcePath() + L" " +
                L"project.xml" + L" " +
                L"make.py";

    line    = command + L" " + args;

    shell.Print(line);

    shell.Run(line);

    return T100TRUE;
}

T100WSTRING T100ProjectLogic::GetFolderName(const T100WxFolderInfo& info)
{
    return info.GetPath();
}

T100WSTRING T100ProjectLogic::GetBuildName(const T100ProjectInfo* info)
{
    return info->GetPath() + T100ProjectConfig::T100PROJECT_STORAGE_SEPARATOR + T100ProjectConfig::T100PROJECT_PROJECT_COMPILE_FILENAME;
}
