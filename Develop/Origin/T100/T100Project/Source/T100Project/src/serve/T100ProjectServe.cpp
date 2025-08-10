#include "T100ProjectServe.h"

T100ProjectServe::T100ProjectServe() :
    m_logic(),
    m_projects()
{
    //ctor
}

T100ProjectServe::~T100ProjectServe()
{
    //dtor
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
    return m_logic.GetProjectInfo();
}

T100BOOL T100ProjectServe::Check(T100ProjectInfo* info)
{
    return m_logic.Check(info);
}

T100BOOL T100ProjectServe::New(const T100WxFolderInfo& info)
{
    return m_logic.New(info);
}

T100BOOL T100ProjectServe::Open(const T100WSTRING&)
{

}

T100BOOL T100ProjectServe::Open(const T100WSTRING_VECTOR& folders, T100PROJECT_INFO_VECTOR& projects)
{
    for(const T100WSTRING& item : folders){
        if(m_logic.Open(item)){

        }else{
            return T100FALSE;
        }
    }

    m_projects  = &projects;
    return T100TRUE;
}


