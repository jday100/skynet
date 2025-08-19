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

    sizer->Add(listBook, wxALL);

    SetSizer(sizer);

    wxListView*     listView    = T100NEW wxListView(listBook);

    //listView->SetItem(1, 0, L"Traditional");
    //listView->Append(L"Traditional");

    listView->AppendColumn(L"");
    listView->InsertItem(listView->GetItemCount(), L"Traditional");

    listBook->AddPage(listView, L"Traditional");
}

T100VOID T100CreateWizardFirstPage::uninit()
{

}
