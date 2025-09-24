#include "T100FileServe.h"

#include "T100File.h"

T100FileServe::T100FileServe()
{
    //ctor
}

T100FileServe::~T100FileServe()
{
    //dtor
}

T100BOOL T100FileServe::IsOpened(const T100WSTRING& path)
{
    T100FileInfo*       value       = T100NULL;

    value   = m_openedFiles[path];

    if(value){
        return T100TRUE;
    }
    return T100FALSE;
}

T100FileInfo* T100FileServe::GetFileInfo(const T100WSTRING& path)
{
    return m_openedFiles[path];
}

T100FileInfo* T100FileServe::Create()
{
    T100FileInfo*   info    = T100NEW T100FileInfo();

    info->SetLabel(L"unnamed");

    return info;
}

T100BOOL T100FileServe::Open(T100FileInfo* info)
{
    if(!info){
        return T100FALSE;
    }

    T100WSTRING     path        = info->GetPath();
    T100File        file(info->GetPath());

    if(!file.IsExists()){
        return T100FALSE;
    }

    T100FileInfo*       value       = T100NULL;

    value   = m_openedFiles[path];

    if(value){
        return T100FALSE;
    }

    m_openedFiles[path] = info;
    info->SetOpened(T100TRUE);

    return T100TRUE;
}

T100BOOL T100FileServe::Open(T100WxFileInfo& info)
{
    if(info.GetPath().empty()){
        return T100FALSE;
    }

    T100File        file(info.GetPath());

    if(!file.IsExists()){
        return T100FALSE;
    }

    T100FileInfo*       value       = T100NULL;

    value   = m_openedFiles[info.GetPath()];

    if(value){
        return T100FALSE;
    }

    T100FileInfo*   result   = T100NEW T100FileInfo();

    m_openedFiles[info.GetPath()] = result;

    result->SetPath(info.GetPath());
    result->SetLabel(info.GetLabel());
    result->SetOpened(T100TRUE);

    return T100TRUE;
}

T100BOOL T100FileServe::Close(const T100WSTRING& path)
{
    T100FileInfo*       value       = T100NULL;

    value   = m_openedFiles[path];

    if(value){
        m_openedFiles.erase(path);
    }else{
        return T100FALSE;
    }
    return T100TRUE;
}

T100BOOL T100FileServe::Clear()
{
    m_openedFiles.clear();
    return T100TRUE;
}
