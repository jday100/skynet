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

const T100STRING T100PathTools::GetCwd()
{
    T100CHAR        buffer[_MAX_PATH];
    T100STRING      result;

    result = ::_getcwd(buffer, _MAX_PATH);

    return result;
}

T100BOOL T100PathTools::Format(const T100STRING& file, T100STRING& path, T100STRING& name)
{
    T100BOOL        result;
    T100STRING      value;

    result = FullPath(file, value);
    if(!result){
        return T100FALSE;
    }
    result = Split(value, path, name);
    return result;
}

T100BOOL T100PathTools::FullPath(const T100STRING& file, T100STRING& path)
{
    T100CHAR    buffer[_MAX_PATH];
    T100CHAR*   result;

    result = ::_fullpath(buffer, file.c_str(), _MAX_PATH);

    if(!result){
        return T100FALSE;
    }
    path = result;
    return T100TRUE;
}

T100BOOL T100PathTools::Split(const T100STRING& file, T100STRING& path, T100STRING& name)
{
    T100CHAR    drive[_MAX_DRIVE];
    T100CHAR    dir[_MAX_DIR];
    T100CHAR    filename[_MAX_FNAME];
    T100CHAR    ext[_MAX_EXT];

    ::_splitpath(file.c_str(), drive, dir, filename, ext);

    path = drive;
    path += dir;

    name = filename;
    T100STRING     temp;

    temp = ext;
    if(0 < temp.size()){
        name += temp;
    }

    return T100TRUE;
}
