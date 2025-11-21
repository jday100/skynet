#include "gui/T100SaveDialog.h"

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

T100VOID T100SaveDialog::init()
{

}

T100VOID T100SaveDialog::uninit()
{

}

T100BOOL T100SaveDialog::Show()
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
    ofn.Flags           = OFN_PATHMUSTEXIST;

    result  = GetSaveFileName(&ofn);

    m_filename  = filename;

    return result;
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
