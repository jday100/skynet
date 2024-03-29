#include "T100PathTools.h"

#include <io.h>
#include <direct.h>
#include "T100StringTools.h"

namespace T100Library{

T100PathTools::T100PathTools()
    :T100Class()
{
    //ctor
}

T100PathTools::~T100PathTools()
{
    //dtor
}

T100BOOL T100PathTools::format(T100WSTRING file, T100WSTRING& path, T100WSTRING& name)
{
    T100BOOL        result;
    T100WSTRING     value;

    result = full(file, value);
    if(!result){
        return T100FALSE;
    }
    result = split(value, path, name);
    return result;
}

T100BOOL T100PathTools::full(T100WSTRING file, T100WSTRING& path)
{
    T100WCHAR   buffer[_MAX_PATH];
    T100WCHAR*  result;

    result = ::_wfullpath(buffer, file.c_str(), _MAX_PATH);

    if(!result){
        return T100FALSE;
    }
    path = result;
    return T100TRUE;
}

T100BOOL T100PathTools::split(T100WSTRING file, T100WSTRING& path, T100WSTRING& name)
{
    T100WCHAR   drive[_MAX_DRIVE];
    T100WCHAR   dir[_MAX_DIR];
    T100WCHAR   filename[_MAX_FNAME];
    T100WCHAR   ext[_MAX_EXT];

    ::_wsplitpath(file.c_str(), drive, dir, filename, ext);

    path = drive;
    path += dir;

    name = filename;
    T100WSTRING     temp;

    temp = ext;
    if(0 < temp.size()){
        name += temp;
    }

    return T100TRUE;
}

T100BOOL T100PathTools::join(T100WSTRING str1, T100WSTRING str2, T100WSTRING& value)
{
    T100BOOL        result;

    result  = T100StringTools::endsWith(str1, L"\\");
    if(result){
        result  = T100StringTools::startsWith(str2, L"\\");
        if(result){
            value   = str1 + str2.substr(1);
        }else{
            value   = str1 + str2;
        }
    }else{
        result  = T100StringTools::startsWith(str2, L"\\");
        if(result){
            value   = str1 + str2;
        }else{
            value   = str1 + L"\\" + str2;
        }
    }

    return T100TRUE;
}

T100WSTRING T100PathTools::getCwd()
{
    T100WCHAR       buffer[_MAX_PATH];
    T100WSTRING     result;

    result = ::_wgetcwd(buffer, _MAX_PATH);

    return result;
}

T100BOOL T100PathTools::mkdir(T100WSTRING path)
{
    T100INT     result;

    result  = ::_wmkdir(path.c_str());

    if(-1 == result){
        return T100FALSE;
    }
    return T100TRUE;
}

T100BOOL T100PathTools::chdir(T100WSTRING path)
{
    T100INT     result;

    result = ::_wchdir(path.c_str());

    if(-1 == result){
        return T100FALSE;
    }
    return T100TRUE;
}

T100BOOL T100PathTools::rmdir(T100WSTRING path)
{
    T100INT     result;

    result  = ::_wrmdir(path.c_str());

    if(-1 == result){
        return T100FALSE;
    }
    return T100TRUE;
}

T100BOOL T100PathTools::enum_directories(T100WSTRING path, T100DIRECTORY_ENTRY_VECTOR& entries)
{
    long    handle      = 0;

    struct _wfinddata_t  info;

    handle  = _wfindfirst(path.c_str(), &info);

    if(-1 == handle){
        return T100FALSE;
    }else{
        do{
            if(info.attrib & _A_SUBDIR){
                if(wcscmp(info.name, L".") != 0 && wcscmp(info.name, L"..") != 0){
                    T100DirectoryEntry*     entry       = T100NEW T100DirectoryEntry(info.name);
                    entries.push_back(entry);
                }
            }
        }while(-1 != _wfindnext(handle, &info));
        _findclose(handle);
        return T100TRUE;
    }
}

T100BOOL T100PathTools::enum_files(T100WSTRING path, T100DIRECTORY_ENTRY_VECTOR& entries)
{
    long    handle      = 0;

    struct _wfinddata_t  info;

    handle  = _wfindfirst(path.c_str(), &info);

    if(-1 == handle){

    }else{
        do{
            if(info.attrib & _A_SUBDIR){
                if(wcscmp(info.name, L".") != 0 && wcscmp(info.name, L"..") != 0){
                    T100DirectoryEntry*     entry       = T100NEW T100DirectoryEntry(info.name);
                    entries.push_back(entry);
                }
            }
        }while(-1 != _wfindnext(handle, &info));
        _findclose(handle);
    }
}

}
