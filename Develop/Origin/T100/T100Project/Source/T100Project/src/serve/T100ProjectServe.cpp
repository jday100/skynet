#include "T100ProjectServe.h"

T100ProjectServe::T100ProjectServe() :
    m_fileLogic(),
    m_folderLogic(),
    m_projectLogic(),
    m_projects()
{
    //ctor
}

T100ProjectServe::~T100ProjectServe()
{
    //dtor
}

T100FileLogic& T100ProjectServe::GetFileLogic()
{
    return m_fileLogic;
}

T100FolderLogic& T100ProjectServe::GetFolderLogic()
{
    return m_folderLogic;
}

T100ProjectLogic& T100ProjectServe::GetProjectLogic()
{
    return m_projectLogic;
}

T100VOID T100ProjectServe::GetProjects(T100PROJECT_INFO_VECTOR& infos)
{
    infos       = *m_projects;
}

const T100PROJECT_INFO_VECTOR& T100ProjectServe::GetProjects()
{
    return *m_projects;
}

T100ProjectInfo* T100ProjectServe::GetProjectInfo()
{
    return m_projectLogic.GetProjectInfo();
}

T100BOOL T100ProjectServe::Check(T100WxFolderInfo* info)
{
    return m_projectLogic.Check(info);
}

T100BOOL T100ProjectServe::New(const T100WxFolderInfo& info)
{
    return m_projectLogic.NewNew(info);
}

T100BOOL T100ProjectServe::Open(const T100WSTRING&)
{

}

T100BOOL T100ProjectServe::Open(const T100WSTRING_VECTOR& folders, T100PROJECT_INFO_VECTOR& projects)
{
    for(const T100WSTRING& item : folders){
        if(m_projectLogic.Open(item)){

        }else{
            return T100FALSE;
        }
    }

    m_projects  = &projects;
    return T100TRUE;
}


