#include "T100ProjectServe.h"

#include "T100ProjectConfig.h"
#include "T100Folder.h"
#include "T100ProjectFile.h"
#include "T100ModuleInfo.h"
#include "T100ProjectInfo.h"
#include "T100WorkSpaceInfo.h"
#include "T100DebugOutput.h"
#include "T100Execute.h"

T100ProjectServe::T100ProjectServe()
{
    //ctor
}

T100ProjectServe::~T100ProjectServe()
{
    //dtor
}

T100ProjectInfo* T100ProjectServe::GetCurrentProject()
{
    return m_current;
}

const T100WSTRING T100ProjectServe::GetFileName(const T100WSTRING& path)
{
    return path + T100ProjectConfig::T100PROJECT_STORAGE_SEPARATOR + T100ProjectConfig::T100PROJECT_PROJECT_CONFIG_FILENAME;
}

const T100WSTRING T100ProjectServe::GetFolderName(const T100WSTRING& folder, const T100WSTRING& label)
{
    return folder + T100ProjectConfig::T100PROJECT_STORAGE_SEPARATOR + label;
}

T100BOOL T100ProjectServe::Check(T100WxFolderInfo* info)
{
    if(!info){
        return T100FALSE;
    }

    T100WSTRING             filename;

    filename    = GetFileName(info->GetPath());

    T100ProjectFile         file(filename);

    if(!file.IsExists()){
        return T100FALSE;
    }

    if(!file.Check()){
        return T100FALSE;
    }
    return T100TRUE;
}

T100BOOL T100ProjectServe::Create(T100WorkSpaceInfo* workspace, T100ProjectInfo* project)
{
    if(workspace && project){
        if(project->GetBuildFileName().empty()){
            project->SetBuildFileName(project->GetLabel() + T100ProjectConfig::T100PROJECT_STORAGE_SEPARATOR + L".exe");
        }
    }else{
        return T100FALSE;
    }

    T100WSTRING         command;
    T100DebugOutput     output;

    command     = workspace->GetPythonFile() + L" " +
                    workspace->GetExecutePath() + L"\\scripts\\project\\ProjectCreate.py" + L" " +
                    GetFolderName(workspace->GetPath(), project->GetLabel()) + L" " +
                    workspace->GetExecutePath() + L" " +
                    workspace->GetPythonFile() + L" " +
                    project->GetBuildPath() + L" " +
                    project->GetCodePath() + L" " +
                    project->GetIncludePath() + L" " +
                    project->GetSourcePath() + L" " +
                    T100ProjectConfig::T100PROJECT_PROJECT_CONFIG_FILENAME + L" " +
                    T100ProjectConfig::T100PROJECT_PROJECT_COMPILE_FILENAME;

    output.Print(command);

    T100Execute(command, output);

    m_current   = T100NEW T100ProjectInfo();

    m_current->SetLabel(project->GetLabel());
    m_current->SetPath(workspace->GetPath() + T100ProjectConfig::T100PROJECT_STORAGE_SEPARATOR + project->GetLabel());
    m_current->SetBuildFileName(project->GetLabel() + L".exe");
}

T100BOOL T100ProjectServe::Open(T100ProjectInfo* info)
{
    if(!info){
        return T100FALSE;
    }

    if(info->IsOpened()){
        return T100FALSE;
    }

    T100Folder      folder(info->GetPath());

    if(!folder.IsExists()){
        return T100FALSE;
    }

    T100FILE_INFO_VECTOR&           files       = info->GetFiles();
    T100FOLDER_INFO_VECTOR&         folders     = info->GetSubFolders();

    T100WSTRING_VECTOR              fileNames;
    T100WSTRING_VECTOR              folderNames;

    folder.List(folderNames, fileNames);

    for(const T100WSTRING& item : folderNames){
        if(item == info->GetBuildPath() || item == T100ProjectConfig::T100PROJECT_PYTHON_CACHE_FOLDER){
            continue;
        }

        T100WSTRING         thisPath;

        thisPath    = info->GetPath() + T100ProjectConfig::T100PROJECT_STORAGE_SEPARATOR + item;

        T100FolderInfo*     thisFolder      = T100NEW T100FolderInfo();

        thisFolder->SetLabel(item);
        thisFolder->SetPath(thisPath);

        folders.push_back(thisFolder);
    }

    for(const T100WSTRING& item : fileNames){
        if(item == T100ProjectConfig::T100PROJECT_PROJECT_CONFIG_FILENAME){

        }else{
            T100WSTRING         thisPath        = info->GetPath() + T100ProjectConfig::T100PROJECT_STORAGE_SEPARATOR + item;
            T100FileInfo*       thisFile        = T100NEW T100FileInfo();

            thisFile->SetLabel(item);
            thisFile->SetFileName(item);
            thisFile->SetPath(thisPath);

            files.push_back(thisFile);
        }
    }
    m_current   = info;
    return T100TRUE;
}

T100BOOL T100ProjectServe::Build(T100WorkSpaceInfo* workspace, T100ProjectInfo* project)
{
    if(workspace && project){

    }else{
        return T100FALSE;
    }

    T100WSTRING         command;
    T100DebugOutput     output;

    command     = workspace->GetPythonFile() + L" " +
                    m_current->GetPath() + T100ProjectConfig::T100PROJECT_STORAGE_SEPARATOR + T100ProjectConfig::T100PROJECT_PROJECT_COMPILE_FILENAME + L" " +
                    L"build " +
                    m_current->GetPath() + L" " +
                    workspace->GetCompilerPath() + L" " +
                    m_current->GetBuildPath() + L" " +
                    m_current->GetCodePath() + L" " +
                    m_current->GetIncludePath() + L" " +
                    m_current->GetSourcePath() + L" " +
                    m_current->GetBuildFileName();

    output.Print(command);

    T100Execute(command, output);

    return T100TRUE;
}

T100BOOL T100ProjectServe::Run(T100WorkSpaceInfo* workspace, T100ProjectInfo* project)
{
    if(workspace && project){

    }else{
        return T100FALSE;
    }

    T100WSTRING         command;
    T100DebugOutput     output;

    command     = m_current->GetPath() +
                    T100ProjectConfig::T100PROJECT_STORAGE_SEPARATOR +
                    project->GetBuildPath() +
                    T100ProjectConfig::T100PROJECT_STORAGE_SEPARATOR +
                    project->GetBuildFileName();

    output.Print(command);

    T100Execute(command, output);

    return T100TRUE;
}

T100BOOL T100ProjectServe::Clean(T100WorkSpaceInfo* workspace, T100ProjectInfo* project)
{
    if(workspace && project){

    }else{
        return T100FALSE;
    }

    T100WSTRING         command;
    T100DebugOutput     output;

    command     = workspace->GetPythonFile() + L" " +
                    m_current->GetPath() + T100ProjectConfig::T100PROJECT_STORAGE_SEPARATOR + T100ProjectConfig::T100PROJECT_PROJECT_COMPILE_FILENAME + L" " +
                    L"clean " +
                    m_current->GetPath() + L" " +
                    workspace->GetCompilerPath() + L" " +
                    m_current->GetBuildPath() + L" " +
                    m_current->GetCodePath() + L" " +
                    m_current->GetIncludePath() + L" " +
                    m_current->GetSourcePath() + L" " +
                    m_current->GetBuildFileName();

    output.Print(command);

    T100Execute(command, output);

    return T100TRUE;
}

T100BOOL T100ProjectServe::ModuleCreate(T100WorkSpaceInfo* workspace, T100ModuleInfo* info)
{
    if(workspace && m_current && info){

    }else{
        return T100FALSE;
    }

    T100WSTRING         command;
    T100DebugOutput     output;

    command     = workspace->GetPythonFile() + L" " +
                    workspace->GetExecutePath() + L"\\scripts\\project\\Module.py" + L" " +
                    m_current->GetPath() + L" " +
                    m_current->GetCodePath() + L" " +
                    m_current->GetIncludePath() + L" " +
                    m_current->GetSourcePath() + L" " +
                    info->GetLabel() + L" " +
                    info->GetIncludeFile()->GetFileName() + L" " +
                    info->GetSourceFile()->GetFileName();

    output.Print(command);

    T100Execute(command, output);

    return T100TRUE;
}

T100BOOL T100ProjectServe::Clear()
{
    T100SAFE_DELETE(m_current);
    return T100TRUE;
}
