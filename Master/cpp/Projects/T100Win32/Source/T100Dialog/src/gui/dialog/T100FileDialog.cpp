#include "T100FileDialog.h"

T100FileDialog::T100FileDialog() :
    T100Window()
{
    //ctor
    Init();
}

T100FileDialog::~T100FileDialog()
{
    //dtor
}


T100VOID T100FileDialog::Init()
{
    OPENFILENAME    ofn;
    T100WCHAR       filename[MAX_PATH];

    ZeroMemory(&ofn, sizeof(OPENFILENAME));

    ofn.lStructSize = sizeof(OPENFILENAME);



    ofn.lpstrFilter     = L"All\0*.*\0";
    ofn.nFilterIndex    = 1;

    ofn.lpstrFile       = filename;
    ofn.lpstrFile[0]    = L'\0';

    ofn.nMaxFile        = sizeof(filename);
    ofn.Flags           = OFN_FILEMUSTEXIST | OFN_PATHMUSTEXIST;

    GetOpenFileName(&ofn);
}

T100VOID T100FileDialog::SetDirectory(T100WSTRING value)
{
    m_directory     = value;
}

T100WSTRING& T100FileDialog::GetDirectory()
{
    return m_directory;
}

T100VOID T100FileDialog::SetPath(T100WSTRING value)
{
    m_path      = value;
}

T100WSTRING& T100FileDialog::GetPath()
{
    return m_path;
}

T100VOID T100FileDialog::SetFileName(T100WSTRING value)
{
    m_fileName  = value;
}

T100WSTRING& T100FileDialog::GetFileName()
{
    return m_fileName;
}
