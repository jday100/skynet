#include "T100SaveDialog.h"

namespace T100WINDOWS{

T100SaveDialog::T100SaveDialog() :
    T100Dialog()
{
    //ctor
}

T100SaveDialog::~T100SaveDialog()
{
    //dtor
}

T100VOID T100SaveDialog::SetDirectory(const T100WSTRING& value)
{
    m_directory     = value;
}

const T100WSTRING& T100SaveDialog::GetDirectory()
{
    return m_directory;
}

T100VOID T100SaveDialog::SetPath(const T100WSTRING& value)
{
    m_path      = value;
}

const T100WSTRING& T100SaveDialog::GetPath()
{
    return m_path;
}

T100VOID T100SaveDialog::SetFileName(const T100WSTRING& value)
{
    m_filename  = value;
}

const T100WSTRING& T100SaveDialog::GetFileName()
{
    return m_filename;
}

}
