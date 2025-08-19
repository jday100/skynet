#include "T100CreateWizardSecondPage.h"

#include <wx/sizer.h>

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

    SetSizer(sizer);
    sizer->Fit(this);
    sizer->SetSizeHints(this);
}

T100VOID T100CreateWizardSecondPage::uninit()
{

}
