#include "T100FileDialog.h"

T100FileDialog::T100FileDialog() :
    T100SelfLoopWindow()
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
