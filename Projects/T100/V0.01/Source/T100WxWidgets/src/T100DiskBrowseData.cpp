#include "T100DiskBrowseData.h"

T100DiskBrowseData::T100DiskBrowseData(const wxString& path, const wxString& name, bool isDir)
    :wxDirItemData(path, name, isDir)
{
    //ctor
}

T100DiskBrowseData::~T100DiskBrowseData()
{
    //dtor
}

T100VOID T100DiskBrowseData::setPart(T100BOOL flag)
{
    m_part = flag;
}

T100BOOL T100DiskBrowseData::isPart()
{
    return m_part;
}
