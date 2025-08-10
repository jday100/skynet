#include "T100FSEntry.h"

#include <io.h>

T100FSEntry::T100FSEntry(const T100WSTRING& name) :
    m_entryName(name)
{
    //ctor
}

T100FSEntry::~T100FSEntry()
{
    //dtor
}

T100VOID T100FSEntry::SetEntryName(const T100WSTRING& name)
{
    m_entryName = name;
}

const T100WSTRING& T100FSEntry::GetEntryName()
{
    return m_entryName;
}

T100BOOL T100FSEntry::IsExists()
{
    T100INT     result;

    result = ::_waccess(m_entryName.c_str(), F_OK);

    if(-1 == result){

    }else{
        return T100TRUE;
    }

    return T100FALSE;
}
