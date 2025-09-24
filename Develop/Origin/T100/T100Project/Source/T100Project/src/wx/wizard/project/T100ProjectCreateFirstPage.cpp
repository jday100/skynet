#include "T100ProjectCreateFirstPage.h"

#include <wx/listbook.h>
#include <wx/listctrl.h>

T100ProjectCreateFirstPage::T100ProjectCreateFirstPage(wxWizard *parent,
                       wxWizardPage *prev,
                       wxWizardPage *next,
                       const wxBitmap& bitmap) :
    wxWizardPageSimple(parent, prev, next, bitmap)
{
    //ctor
    init();
}

T100ProjectCreateFirstPage::~T100ProjectCreateFirstPage()
{
    //dtor
    uninit();
}

T100VOID T100ProjectCreateFirstPage::init()
{
    wxBoxSizer*     sizer   = T100NEW wxBoxSizer(wxVERTICAL);
    wxListbook*     book    = T100NEW wxListbook(this, wxID_ANY);

    sizer->Add(book, 1, wxALL|wxEXPAND, 5);

    SetSizer(sizer);

    wxListView*     view    = T100NEW wxListView(book);

    view->AppendColumn(L"Project");
    view->InsertItem(view->GetItemCount(), L"Traditional");

    book->AddPage(view, L"Traditional");

    sizer->Fit(this);
    sizer->SetSizeHints(this);
}

T100VOID T100ProjectCreateFirstPage::uninit()
{

}

T100BOOL T100ProjectCreateFirstPage::TransferDataToWindow()
{

}

T100BOOL T100ProjectCreateFirstPage::TransferDataFromWindow()
{
    return T100TRUE;
}
