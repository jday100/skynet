#include "T100DirectoryEntry.h"

#include <io.h>


T100DirectoryEntry::T100DirectoryEntry(T100WSTRING name)
    :m_name(name)
{
    //ctor
}

T100DirectoryEntry::~T100DirectoryEntry()
{
    //dtor
}

T100BOOL T100DirectoryEntry::exists()
{
    T100INT         result;

    result = ::_waccess(m_name.c_str(), F_OK);

    if(-1 == result){

    }else{
        return T100TRUE;
    }

    return T100FALSE;
}

T100WSTRING T100DirectoryEntry::getName()
{
    return m_name;
}
