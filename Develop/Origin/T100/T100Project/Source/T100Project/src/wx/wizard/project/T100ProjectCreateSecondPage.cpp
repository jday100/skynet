#include "T100ProjectCreateSecondPage.h"

#include <wx/msgdlg.h>

const long T100ProjectCreateSecondPage::ID_PROJECT_NAME_TITLE   = wxNewId();
const long T100ProjectCreateSecondPage::ID_PROJECT_NAME_LABEL   = wxNewId();

T100ProjectCreateSecondPage::T100ProjectCreateSecondPage(wxWizard *parent,
                       wxWizardPage *prev,
                       wxWizardPage *next,
                       const wxBitmap& bitmap) :
    wxWizardPageSimple(parent, prev, next, bitmap)
{
    //ctor
    init();
}

T100ProjectCreateSecondPage::~T100ProjectCreateSecondPage()
{
    //dtor
    uninit();
}

T100VOID T100ProjectCreateSecondPage::init()
{
    wxBoxSizer*     sizer       = T100NEW wxBoxSizer(wxVERTICAL);

    wxStaticBoxSizer*   project     = T100NEW wxStaticBoxSizer(wxHORIZONTAL, this, _("Project:"));

    m_title     = T100NEW wxStaticText(this, ID_PROJECT_NAME_TITLE, _("Name:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_PROJECT_NAME_TITLE"));
    m_label     = T100NEW wxTextCtrl(this, ID_PROJECT_NAME_LABEL, _(""));


    project->Add(m_title, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    project->Add(m_label, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);

    sizer->Add(project, 1, wxALL|wxEXPAND, 5);

    SetSizer(sizer);
    sizer->Fit(this);
    sizer->SetSizeHints(this);
}

T100VOID T100ProjectCreateSecondPage::uninit()
{

}

const T100WSTRING T100ProjectCreateSecondPage::GetLabel()
{
    return m_label->GetValue().ToStdWstring();
}

T100BOOL T100ProjectCreateSecondPage::TransferDataToWindow()
{

}

T100BOOL T100ProjectCreateSecondPage::TransferDataFromWindow()
{
    if(m_label->GetValue().empty()){
        wxMessageBox(wxT("Please input a name!"), wxT("Error"),
                     wxICON_WARNING | wxOK, this);
        return T100FALSE;
    }
    return T100TRUE;
}
