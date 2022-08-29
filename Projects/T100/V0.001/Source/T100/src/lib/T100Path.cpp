#include "T100Path.h"

#include <direct.h>


T100Path::T100Path()
{
    //ctor
}

T100Path::~T100Path()
{
    //dtor
}

T100BOOL T100Path::format(T100STDSTRING file, T100STDSTRING& path, T100STDSTRING& name)
{
    T100STDSTRING result;

    full(file, result);
    split(result, path, name);

    return T100TRUE;
}

T100BOOL T100Path::full(T100STDSTRING file, T100STDSTRING& path)
{
    T100STDCHAR buffer[_MAX_PATH];

    ::_fullpath(buffer, file.c_str(), _MAX_PATH);

    path = buffer;

    return T100TRUE;
}

T100BOOL T100Path::split(T100STDSTRING file, T100STDSTRING& path, T100STDSTRING& name)
{
    T100STDCHAR drive[_MAX_DRIVE];
    T100STDCHAR dir[_MAX_DIR];
    T100STDCHAR filename[_MAX_FNAME];
    T100STDCHAR ext[_MAX_EXT];

    ::_splitpath(file.c_str(), drive, dir, filename, ext);

    path = drive;
    path += dir;

    name = filename;
    T100STDSTRING temp;

    temp = ext;
    if(temp.size() > 0){
        name += temp;
    }

    return T100TRUE;
}

T100STDSTRING T100Path::getCwd()
{
    T100STDCHAR     buffer[_MAX_PATH];
    T100STDSTRING   result;

    result = ::_getcwd(buffer, _MAX_PATH);

    return result;
}

T100BOOL T100Path::chdir(T100STDSTRING path)
{
    T100INTEGER result;

    result = ::_chdir(path.c_str());

    if(-1 == result){
        return T100FALSE;
    }

    return T100TRUE;
}
