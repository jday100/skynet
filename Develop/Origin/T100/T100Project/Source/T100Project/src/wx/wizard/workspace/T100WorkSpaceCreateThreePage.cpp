#include "T100WorkSpaceCreateThreePage.h"

#include <wx/msgdlg.h>

T100WorkSpaceCreateThreePage::T100WorkSpaceCreateThreePage(wxWizard *parent,
                       wxWizardPage *prev,
                       wxWizardPage *next,
                       const wxBitmap& bitmap) :
    wxWizardPageSimple(parent, prev, next, bitmap)
{
    //ctor
    init();
}

T100WorkSpaceCreateThreePage::~T100WorkSpaceCreateThreePage()
{
    //dtor
    uninit();
}

T100VOID T100WorkSpaceCreateThreePage::init()
{
    m_pythonPanel       = T100NEW T100PythonPanel(this);
}

T100VOID T100WorkSpaceCreateThreePage::uninit()
{
    T100SAFE_DELETE(m_pythonPanel);
}

const T100WSTRING T100WorkSpaceCreateThreePage::GetPath()
{
    return m_pythonPanel->GetPath();
}

T100BOOL T100WorkSpaceCreateThreePage::TransferDataToWindow()
{
    return T100TRUE;
}

T100BOOL T100WorkSpaceCreateThreePage::TransferDataFromWindow()
{
    if(m_pythonPanel->GetPath().empty()){
        wxMessageBox(wxT("Please select a python's execute file"), wxT("Error"),
                     wxICON_WARNING | wxOK, this);
        return T100FALSE;
    }
    return T100TRUE;
}
