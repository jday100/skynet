#include "T100ProjectCreateWizard.h"

#include "T100ProjectInvoking.h"

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
    m_first     = T100NEW T100ProjectCreateFirstPage(this);
    m_second    = T100NEW T100ProjectCreateSecondPage(this, m_first);

    m_first->SetNext(m_second);
}

T100VOID T100ProjectCreateWizard::uninit()
{
    T100SAFE_DELETE(m_first);
    T100SAFE_DELETE(m_second);
}

wxWizardPage* T100ProjectCreateWizard::GetFirstPage()
{
    return m_first;
}

T100VOID T100ProjectCreateWizard::OnWizardCancel(wxWizardEvent& event)
{

}

T100VOID T100ProjectCreateWizard::OnWizardFinished(wxWizardEvent& event)
{
    m_info.SetLabel(m_second->GetLabel());
    T100ProjectInvoking::OnProjectCreateDone(&m_info);
}
