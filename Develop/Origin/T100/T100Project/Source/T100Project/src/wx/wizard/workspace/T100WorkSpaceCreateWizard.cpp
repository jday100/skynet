#include "T100WorkSpaceCreateWizard.h"

#include "T100ProjectInvoking.h"

BEGIN_EVENT_TABLE(T100WorkSpaceCreateWizard, wxWizard)
    EVT_WIZARD_CANCEL(wxID_ANY, T100WorkSpaceCreateWizard::OnWizardCancel)
    EVT_WIZARD_FINISHED(wxID_ANY, T100WorkSpaceCreateWizard::OnWizardFinished)
END_EVENT_TABLE()

T100WorkSpaceCreateWizard::T100WorkSpaceCreateWizard(wxWindow *parent,
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

T100WorkSpaceCreateWizard::~T100WorkSpaceCreateWizard()
{
    //dtor
    uninit();
}

T100VOID T100WorkSpaceCreateWizard::init()
{
    m_first     = T100NEW T100WorkSpaceCreateFirstPage(this);
    m_second    = T100NEW T100WorkSpaceCreateSecondPage(this);
    m_three     = T100NEW T100WorkSpaceCreateThreePage(this);

    m_first->SetNext(m_second);
    m_second->SetPrev(m_first);
    m_second->SetNext(m_three);
    m_three->SetPrev(m_second);
}

T100VOID T100WorkSpaceCreateWizard::uninit()
{
    T100SAFE_DELETE(m_first);
    T100SAFE_DELETE(m_second);
    T100SAFE_DELETE(m_three);
}

wxWizardPage* T100WorkSpaceCreateWizard::GetFirstPage()
{
    return m_first;
}

T100VOID T100WorkSpaceCreateWizard::OnWizardCancel(wxWizardEvent& event)
{

}

T100VOID T100WorkSpaceCreateWizard::OnWizardFinished(wxWizardEvent& event)
{
    m_info.SetPath(m_first->GetPath());
    m_info.SetCompilerPath(m_second->GetPath());
    m_info.SetPythonFile(m_three->GetPath());

    T100ProjectInvoking::OnWorkSpaceCreateDone(&m_info);
}
