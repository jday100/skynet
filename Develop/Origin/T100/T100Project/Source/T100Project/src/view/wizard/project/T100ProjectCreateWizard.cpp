#include "T100ProjectCreateWizard.h"

#include "T100ProjectInvoking.h"
#include "T100CreateWizardFirstPage.h"


BEGIN_EVENT_TABLE(T100ProjectCreateWizard, wxWizard)
    EVT_WIZARD_CANCEL(wxID_ANY, T100ProjectCreateWizard::OnWizardCancel)
    EVT_WIZARD_FINISHED(wxID_ANY, T100ProjectCreateWizard::OnWizardFinished)
END_EVENT_TABLE()

T100ProjectCreateWizard::T100ProjectCreateWizard(wxWindow *parent,
             int id,
             const wxString& title,
             const wxBitmap& bitmap,
             const wxPoint& pos,
             long style) :
    wxWizard(parent, id, title, bitmap, pos, style)
{
    //ctor
    init();
}

T100ProjectCreateWizard::~T100ProjectCreateWizard()
{
    //dtor
    uninit();
}

T100VOID T100ProjectCreateWizard::init()
{
    m_page      = T100NEW T100CreateWizardFirstPage(this);

}

T100VOID T100ProjectCreateWizard::uninit()
{

}

wxWizardPage* T100ProjectCreateWizard::GetFirstPage()
{
    return m_page;
}

T100VOID T100ProjectCreateWizard::OnWizardCancel(wxWizardEvent& event)
{

}

T100VOID T100ProjectCreateWizard::OnWizardFinished(wxWizardEvent& event)
{
    T100ProjectInvoking::OnProjectCreateWizardFinished();
}
