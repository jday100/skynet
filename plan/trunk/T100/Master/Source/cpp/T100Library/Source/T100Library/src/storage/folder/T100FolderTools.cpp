#include "storage/folder/T100FolderTools.h"

#include "storage/folder/T100Folder.h"

namespace T100LIBRARY{

T100FolderTools::T100FolderTools() :
    T100Class()
{
    //ctor
}

T100FolderTools::~T100FolderTools()
{
    //dtor
}

T100INT T100FolderTools::GetAllFiles(const T100WSTRING& path, T100WSTRING_VECTOR&,
    const T100WSTRING& filespec, T100INT flags)
{
    T100Folder      folder(path);

    T100WSTRING     filename;
    T100BOOL        result;

    do{
        result  = folder.FindFirst(filename, filespec, flags);
    }while(result);
}

}
