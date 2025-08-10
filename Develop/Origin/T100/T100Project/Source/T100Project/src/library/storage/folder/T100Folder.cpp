#include "T100Folder.h"

#include <io.h>

T100Folder::T100Folder(const T100WSTRING& path) :
    T100FSEntry(path)
{
    //ctor
}

T100Folder::~T100Folder()
{
    //dtor
}

T100BOOL T100Folder::Create()
{
    T100INT         result;

    result  = _wmkdir(m_entryName.c_str());

    if(-1 == result){
        return T100FALSE;
    }
    return T100TRUE;
}

T100VOID T100Folder::GetAllSubFolders(T100WSTRING_VECTOR& folders)
{
    long        handle      = 0;

    struct _wfinddata64_t       info;

    T100WSTRING     path    = m_entryName + L"/*.*";

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

T100VOID T100Folder::GetAllFiles(T100WSTRING_VECTOR& files)
{
    long        handle      = 0;

    struct _wfinddata64_t       info;

    T100WSTRING     path    = m_entryName + L"/*.*";

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
