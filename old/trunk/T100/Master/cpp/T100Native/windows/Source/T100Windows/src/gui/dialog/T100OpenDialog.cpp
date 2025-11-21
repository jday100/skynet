#include "gui/T100OpenDialog.h"

namespace T100WINDOWS{

T100OpenDialog::T100OpenDialog() :
    T100Dialog()
{
    //ctor
}

T100OpenDialog::~T100OpenDialog()
{
    //dtor
}

T100VOID T100OpenDialog::init()
{

}

T100VOID T100OpenDialog::uninit()
{

}

T100BOOL T100OpenDialog::Show()
{
    T100BOOL            result;
    OPENFILENAME        ofn;
    T100WCHAR           filename[MAX_PATH];

    ZeroMemory(&ofn, sizeof(OPENFILENAME));

    ofn.lStructSize     = sizeof(OPENFILENAME);

    ofn.lpstrFilter     = L"All\0*.*\0";
    ofn.nFilterIndex    = 1;

    ofn.lpstrFile       = filename;
    ofn.lpstrFile[0]    = L'\0';

    ofn.nMaxFile        = sizeof(filename);
    ofn.Flags           = OFN_FILEMUSTEXIST | OFN_PATHMUSTEXIST;

    result  = GetOpenFileName(&ofn);

    m_filename  = filename;

    return result;
}

T100VOID T100OpenDialog::SetDirectory(const T100WSTRING& value)
{
    m_directory     = value;
}

const T100WSTRING& T100OpenDialog::GetDirectory()
{
    return m_directory;
}

T100VOID T100OpenDialog::SetPath(const T100WSTRING& value)
{
    m_path      = value;
}

const T100WSTRING& T100OpenDialog::GetPath()
{
    return m_path;
}

T100VOID T100OpenDialog::SetFileName(const T100WSTRING& value)
{
    m_filename  = value;
}

const T100WSTRING& T100OpenDialog::GetFileName()
{
    return m_filename;
}

}
