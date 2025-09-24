#include "T100WorkSpaceCreateSecondPage.h"

#include <wx/msgdlg.h>

T100WorkSpaceCreateSecondPage::T100WorkSpaceCreateSecondPage(wxWizard *parent,
                       wxWizardPage *prev,
                       wxWizardPage *next,
                       const wxBitmap& bitmap) :
    wxWizardPageSimple(parent, prev, next, bitmap)
{
    //ctor
    init();
}

T100WorkSpaceCreateSecondPage::~T100WorkSpaceCreateSecondPage()
{
    //dtor
    uninit();
}

T100VOID T100WorkSpaceCreateSecondPage::init()
{
    m_compilerPanel     = T100NEW T100CompilerPanel(this);
}

T100VOID T100WorkSpaceCreateSecondPage::uninit()
{
    T100SAFE_DELETE(m_compilerPanel);
}

const T100WSTRING T100WorkSpaceCreateSecondPage::GetPath()
{
    return m_compilerPanel->GetPath();
}

T100BOOL T100WorkSpaceCreateSecondPage::TransferDataToWindow()
{
    return T100TRUE;
}

T100BOOL T100WorkSpaceCreateSecondPage::TransferDataFromWindow()
{
    if(m_compilerPanel->GetPath().empty()){
        wxMessageBox(wxT("Please select a directory"), wxT("Error"),
                     wxICON_WARNING | wxOK, this);
        return T100FALSE;
    }
    return T100TRUE;
}
