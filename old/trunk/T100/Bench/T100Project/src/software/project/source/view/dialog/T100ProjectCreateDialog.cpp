#include "T100ProjectCreateDialog.h"

#include <wx/sizer.h>
#include <wx/button.h>
#include <wx/treebook.h>

T100ProjectCreateDialog::T100ProjectCreateDialog(
            wxWindow *parent, wxWindowID id,
            const wxString& title,
            const wxPoint& pos,
            const wxSize& size,
            long style,
            const wxString& name) :
    wxDialog(parent, id, title, pos, size, style, name)
{
    //ctor
    init();
}

T100ProjectCreateDialog::~T100ProjectCreateDialog()
{
    //dtor
    uninit();
}

T100VOID T100ProjectCreateDialog::init()
{
    wxBoxSizer*     sizer           = T100NEW wxBoxSizer(wxHORIZONTAL);

    wxTreebook*     treebook        = T100NEW wxTreebook(this, wxID_ANY);

    wxPanel*        panel           = T100NEW wxPanel(treebook);

    treebook->AddPage(panel, L"Project");
    treebook->AddPage(panel, L"Project");

    treebook->Connect(wxEVT_TREEBOOK_PAGE_CHANGED, (wxObjectEventFunction)&OnSelected, T100NULL, this);

    sizer->Add(treebook, 1, wxALL | wxEXPAND, 0);

    wxButton*       button          = T100NEW wxButton(this, wxID_ANY, L"OK");

    button->Connect(wxEVT_BUTTON, (wxObjectEventFunction)&On, T100NULL, this);

    sizer->Add(button, 0, wxALL, 0);

    SetSizer(sizer);
    sizer->Fit(this);
    sizer->SetSizeHints(this);

    SetSize(800, 600);
}

T100VOID T100ProjectCreateDialog::uninit()
{

}

T100VOID T100ProjectCreateDialog::On(wxCommandEvent& event)
{
    Hide();
}

T100VOID T100ProjectCreateDialog::OnSelected(wxTreebookEvent& event)
{

}
