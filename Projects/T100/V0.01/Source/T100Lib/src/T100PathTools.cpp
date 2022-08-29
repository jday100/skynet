#include "T100PathTools.h"

#include <direct.h>


T100PathTools::T100PathTools()
{
    //ctor
}

T100PathTools::~T100PathTools()
{
    //dtor
}

T100BOOL T100PathTools::format(T100WSTRING file, T100WSTRING& path, T100WSTRING& name)
{
    T100WSTRING result;

    full(file, result);
    split(result, path, name);

    return T100TRUE;
}

T100BOOL T100PathTools::full(T100WSTRING file, T100WSTRING& path)
{
    T100WCHAR buffer[_MAX_PATH];

    ::_wfullpath(buffer, file.c_str(), _MAX_PATH);

    path = buffer;

    return T100TRUE;
}

T100BOOL T100PathTools::split(T100WSTRING file, T100WSTRING& path, T100WSTRING& name)
{
    T100WCHAR drive[_MAX_DRIVE];
    T100WCHAR dir[_MAX_DIR];
    T100WCHAR filename[_MAX_FNAME];
    T100WCHAR ext[_MAX_EXT];

    ::_wsplitpath(file.c_str(), drive, dir, filename, ext);

    path = drive;
    path += dir;

    name = filename;
    T100WSTRING temp;

    temp = ext;
    if(temp.size() > 0){
        name += temp;
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

T100BOOL T100PathTools::chdir(T100WSTRING path)
{
    T100INT     result;

    result = ::_wchdir(path.c_str());

    if(-1 == result){
        return T100FALSE;
    }

    return T100TRUE;
}
