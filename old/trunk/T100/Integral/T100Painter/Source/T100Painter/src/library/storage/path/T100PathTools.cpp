#include "T100PathTools.h"

#include <io.h>
#include <direct.h>

T100PathTools::T100PathTools()
{
    //ctor
}

T100PathTools::~T100PathTools()
{
    //dtor
}

const T100WSTRING T100PathTools::GetCwd()
{
    T100WCHAR       buffer[_MAX_PATH];
    T100WSTRING     result;

    result = ::_wgetcwd(buffer, _MAX_PATH);

    return result;
}

T100BOOL T100PathTools::Format(const T100WSTRING& file, T100WSTRING& path, T100WSTRING& name)
{
    T100BOOL        result;
    T100WSTRING     value;

    result = FullPath(file, value);
    if(!result){
        return T100FALSE;
    }
    result = Split(value, path, name);
    return result;
}

T100BOOL T100PathTools::FullPath(const T100WSTRING& file, T100WSTRING& path)
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

T100BOOL T100PathTools::Split(const T100WSTRING& file, T100WSTRING& path, T100WSTRING& name)
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
