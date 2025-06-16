#include "storage/filesystem/T100FileSystemEntry.h"

#include <io.h>

namespace T100LIBRARY{

T100FileSystemEntry::T100FileSystemEntry(const T100WSTRING& name) :
    T100Class(),
    m_entryName(name)
{
    //ctor
}

T100FileSystemEntry::~T100FileSystemEntry()
{
    //dtor
}

T100VOID T100FileSystemEntry::SetEntryName(const T100WSTRING& name)
{
    m_entryName = name;
}

const T100WSTRING& T100FileSystemEntry::GetEntryName()
{
    return m_entryName;
}

T100BOOL T100FileSystemEntry::IsExists()
{
    T100INT     result;

    result = ::_waccess(m_entryName.c_str(), F_OK);

    if(-1 == result){

    }else{
        return T100TRUE;
    }

    return T100FALSE;
}

}
