#include "storage/folder/T100Folder.h"

namespace T100LIBRARY{

T100Folder::T100Folder(const T100WSTRING& name) :
    T100FileSystemEntry(name)
{
    //ctor
}

T100Folder::~T100Folder()
{
    //dtor
}

T100BOOL T100Folder::FindFirst(T100WSTRING& filename, const T100WSTRING& filespec, T100INT flags)
{

}

T100BOOL T100Folder::FindNext(T100WSTRING& filename)
{

}

T100BOOL T100Folder::FindFinished()
{

}

}
