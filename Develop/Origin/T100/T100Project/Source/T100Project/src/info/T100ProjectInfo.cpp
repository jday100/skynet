#include "T100ProjectInfo.h"

T100ProjectInfo::T100ProjectInfo()
{
    //ctor
    init();
}

T100ProjectInfo::~T100ProjectInfo()
{
    //dtor
    uninit();
}

T100VOID T100ProjectInfo::init()
{
    m_opened    = T100FALSE;
}

T100VOID T100ProjectInfo::uninit()
{

}

T100VOID T100ProjectInfo::SetOpened(T100BOOL value)
{
    m_opened        = value;
}

T100BOOL T100ProjectInfo::IsOpened()
{
    return m_opened;
}

T100VOID T100ProjectInfo::SetLabel(const T100WSTRING& label)
{
    m_label     = label;
}

const T100WSTRING& T100ProjectInfo::GetLabel()
{
    return m_label;
}

T100VOID T100ProjectInfo::SetPath(const T100WSTRING& path)
{
    m_path      = path;
}

const T100WSTRING& T100ProjectInfo::GetPath()
{
    return m_path;
}

T100VOID T100ProjectInfo::SetFileName(const T100WSTRING& filename)
{
    m_filename      = filename;
}

const T100WSTRING& T100ProjectInfo::GetFileName()
{
    return m_filename;
}

T100FILE_INFO_VECTOR& T100ProjectInfo::GetFiles()
{
    return m_files;
}

T100FOLDER_INFO_VECTOR& T100ProjectInfo::GetSubFolders()
{
    return m_folders;
}
