#include "T100Folder.h"

#include <io.h>

T100Folder::T100Folder(const T100WSTRING& path) :
    m_path(path)
{
    //ctor
}

T100Folder::~T100Folder()
{
    //dtor
}

T100VOID T100Folder::SetPath(const T100WSTRING& path)
{
    m_path      = path;
}

const T100WSTRING& T100Folder::GetPath()
{
    return m_path;
}

T100BOOL T100Folder::IsExists()
{
    T100INT         result;

    result  = ::_waccess(m_path.c_str(), F_OK);

    if(-1 == result){

    }else{
        return T100TRUE;
    }
    return T100FALSE;
}

T100BOOL T100Folder::Create()
{
    T100INT         result;

    result  = _wmkdir(m_path.c_str());

    if(-1 == result){
        return T100FALSE;
    }
    return T100TRUE;
}

T100VOID T100Folder::GetAllFiles(T100WSTRING_VECTOR& files)
{
    long        handle      = 0;

    struct _wfinddata64_t       info;

    T100WSTRING     path    = m_path + L"/*.*";

    handle  = _wfindfirst64(path.c_str(), &info);

    if(-1 == handle){
        return;
    }else{
        do{
            if(info.attrib & _A_NORMAL){
                files.push_back(info.name);
            }
        }while(-1 != _wfindnext64(handle, &info));
        _findclose(handle);
    }
}

T100VOID T100Folder::GetAllSubFolders(T100WSTRING_VECTOR& folders)
{
    long        handle      = 0;

    struct _wfinddata64_t       info;

    T100WSTRING     path    = m_path + L"/*.*";

    handle  = _wfindfirst64(path.c_str(), &info);

    if(-1 == handle){
        return;
    }else{
        do{
            if(info.attrib & _A_SUBDIR){
                if(wcscmp(info.name, L".") != 0 && wcscmp(info.name, L"..") != 0){
                    folders.push_back(info.name);
                }
            }
        }while(-1 != _wfindnext64(handle, &info));
        _findclose(handle);
    }
}

T100VOID T100Folder::List(T100WSTRING_VECTOR& folders, T100WSTRING_VECTOR& files)
{
    long        handle      = 0;

    struct _wfinddata64_t       info;

    T100WSTRING     path    = m_path + L"/*.*";

    handle  = _wfindfirst64(path.c_str(), &info);

    if(-1 == handle){
        return;
    }else{
        do{
            if(info.attrib == _A_NORMAL ||
               info.attrib == _A_ARCH){
                files.push_back(info.name);
            }else if(info.attrib & _A_SUBDIR){
                if(wcscmp(info.name, L".") != 0 && wcscmp(info.name, L"..") != 0){
                    folders.push_back(info.name);
                }
            }
        }while(-1 != _wfindnext64(handle, &info));
        _findclose(handle);
    }
}
