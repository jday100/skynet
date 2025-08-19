#include "T100CreateWizardFirstPage.h"

#include <wx/sizer.h>
#include <wx/listbook.h>
#include <wx/listctrl.h>

T100CreateWizardFirstPage::T100CreateWizardFirstPage(wxWizard* parent,
    wxWizardPage* prev,
    wxWizardPage* next,
    const wxBitmap& bitmap) :
    wxWizardPageSimple(parent, prev, next, bitmap)
{
    //ctor
    init();
}

T100CreateWizardFirstPage::~T100CreateWizardFirstPage()
{
    //dtor
    uninit();
}

T100VOID T100CreateWizardFirstPage::init()
{
    wxListbook*     listBook    = T100NEW wxListbook(this, wxID_ANY);

    wxBoxSizer*     sizer       = T100NEW wxBoxSizer(wxVERTICAL);

    sizer->Add(listBook, 1, wxALL|wxEXPAND, 5);

    SetSizer(sizer);

    wxListView*     listView    = T100NEW wxListView(listBook);

    listView->AppendColumn(L"Project");
    listView->InsertItem(listView->GetItemCount(), L"Traditional");

    listBook->AddPage(listView, L"Traditional");

    sizer->Fit(this);
    sizer->SetSizeHints(this);
}

T100VOID T100CreateWizardFirstPage::uninit()
{

}
