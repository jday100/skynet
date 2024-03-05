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

T100BOOL T100PathTools::format(T100STRING file, T100STRING& path, T100STRING& name)
{
    T100BOOL            result;
    T100STRING          value;

    result  = full(file, value);
    if(!result){
        return T100FALSE;
    }

    result  = split(value, path, name);
    return result;
}

T100BOOL T100PathTools::full(T100STRING file, T100STRING& path)
{
    T100WCHAR           buffer[_MAX_PATH];
    T100WCHAR*          result;

    result  = ::_wfullpath(buffer, file.c_str(), _MAX_PATH);

    if(!result){
        return T100FALSE;
    }

    path    = result;
    return T100TRUE;
}

T100BOOL T100PathTools::split(T100STRING file, T100STRING& path, T100STRING& name)
{
    T100WCHAR           drive[_MAX_DRIVE];
    T100WCHAR           dir[_MAX_DIR];
    T100WCHAR           filename[_MAX_FNAME];
    T100WCHAR           ext[_MAX_EXT];

    ::_wsplitpath(file.c_str(), drive, dir, filename, ext);

    path    = drive;
    path    += dir;

    name    = filename;

    T100STRING          temp;

    temp    = ext;
    if(0 < temp.length()){
        name    += temp;
    }

    return T100TRUE;
}

T100STRING T100PathTools::getCwd()
{
    T100WCHAR           buffer[_MAX_PATH];
    T100STRING          result;

    result  = ::_wgetcwd(buffer, _MAX_PATH);

    return result;
}

T100BOOL T100PathTools::chdir(T100STRING path)
{
    INT32           result;

    result  = ::_wchdir(path.c_str());

    if(-1 == result){
        return T100FALSE;
    }
    return T100TRUE;
}
