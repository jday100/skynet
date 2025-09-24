#include "T100WorkSpaceCreateFirstPage.h"

#include <wx/msgdlg.h>

const long T100WorkSpaceCreateFirstPage::ID_WORKSPACE_PATH_TITLE    = wxNewId();
const long T100WorkSpaceCreateFirstPage::ID_WORKSPACE_PATH_PICKER   = wxNewId();

T100WorkSpaceCreateFirstPage::T100WorkSpaceCreateFirstPage(wxWizard *parent,
                       wxWizardPage *prev,
                       wxWizardPage *next,
                       const wxBitmap& bitmap) :
    wxWizardPageSimple(parent, prev, next, bitmap)
{
    //ctor
    init();
}

T100WorkSpaceCreateFirstPage::~T100WorkSpaceCreateFirstPage()
{
    //dtor
    uninit();
}

T100VOID T100WorkSpaceCreateFirstPage::init()
{
    wxBoxSizer*     sizer       = T100NEW wxBoxSizer(wxVERTICAL);

    wxStaticBoxSizer*       workspace       = T100NEW wxStaticBoxSizer(wxHORIZONTAL, this, _("WorkSpace:"));

    m_workspaceTitle        = T100NEW wxStaticText(this, ID_WORKSPACE_PATH_TITLE, _("Path:"), wxDefaultPosition, wxSize(30, -1));
    m_workspacePath         = T100NEW wxDirPickerCtrl(this, ID_WORKSPACE_PATH_PICKER);

    workspace->Add(m_workspaceTitle, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    workspace->Add(m_workspacePath, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);

    sizer->Add(workspace, 1, wxALL|wxEXPAND, 5);

    SetSizer(sizer);
    sizer->Fit(this);
    sizer->SetSizeHints(this);
}

T100VOID T100WorkSpaceCreateFirstPage::uninit()
{

}

const T100WSTRING T100WorkSpaceCreateFirstPage::GetPath()
{
    return m_workspacePath->GetPath().ToStdWstring();
}

T100BOOL T100WorkSpaceCreateFirstPage::TransferDataToWindow()
{
    return T100TRUE;
}

T100BOOL T100WorkSpaceCreateFirstPage::TransferDataFromWindow()
{
    if(m_workspacePath->GetPath().empty()){
        wxMessageBox(wxT("Please select a directory"), wxT("Error"),
                     wxICON_WARNING | wxOK, this);
        return T100FALSE;
    }
    return T100TRUE;
}
