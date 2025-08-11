#include "T100ProjectLogic.h"

#include "T100Folder.h"
#include "T100ProjectFile.h"

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

T100ProjectLogic::~T100ProjectLogic()
{
    //dtor
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

    project->SetLabel(L"project");
    project->SetPath(name);
    project->SetFileName(filename);

    m_project   = project;

    return T100TRUE;
}

T100BOOL T100ProjectLogic::Open(const T100WSTRING& value)
{

}

T100WSTRING T100ProjectLogic::GetFileName(const T100WxFolderInfo& info)
{
    return info.GetPath() + L"/project/" + L"project.pjt";
}

T100WSTRING T100ProjectLogic::GetFolderName(const T100WxFolderInfo& info)
{
    return info.GetPath() + L"/project";
}
