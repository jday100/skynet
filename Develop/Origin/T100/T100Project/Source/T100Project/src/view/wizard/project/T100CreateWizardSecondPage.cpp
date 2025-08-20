#include "T100CreateWizardSecondPage.h"

#include <wx/sizer.h>
#include <wx/statbox.h>

const long T100CreateWizardSecondPage::ID_STATICBOX     = wxNewId();
const long T100CreateWizardSecondPage::ID_STATIC_TEXT   = wxNewId();
const long T100CreateWizardSecondPage::ID_TEXT_CTRL     = wxNewId();

T100CreateWizardSecondPage::T100CreateWizardSecondPage(wxWizard* parent,
    wxWizardPage* prev,
    wxWizardPage* next,
    const wxBitmap& bitmap) :
    wxWizardPageSimple(parent, prev, next, bitmap)
{
    //ctor
    init();
}

T100CreateWizardSecondPage::~T100CreateWizardSecondPage()
{
    //dtor
    uninit();
}

T100VOID T100CreateWizardSecondPage::init()
{
    wxBoxSizer*     sizer       = T100NEW wxBoxSizer(wxVERTICAL);

    wxStaticBoxSizer*   staticBox   = T100NEW wxStaticBoxSizer(wxHORIZONTAL, this, _("Project:"));

    m_title     = T100NEW wxStaticText(this, ID_STATIC_TEXT, _("Name:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATIC_TEXT"));
    m_label     = T100NEW wxTextCtrl(this, ID_TEXT_CTRL, _(""));


    staticBox->Add(m_title, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    staticBox->Add(m_label, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);

    sizer->Add(staticBox, 1, wxALL|wxEXPAND, 5);

    SetSizer(sizer);
    sizer->Fit(this);
    sizer->SetSizeHints(this);
}

T100VOID T100CreateWizardSecondPage::uninit()
{

}

const T100WSTRING& T100CreateWizardSecondPage::GetProjectName()
{
    return m_label->GetValue().ToStdWstring();
}
