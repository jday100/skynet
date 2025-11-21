#include "T100ProjectInvoking.h"

#include "T100ProjectApplication.h"

T100ProjectApplication*         T100ProjectInvoking::m_application                      = T100NULL;

T100ProjectInvoking::T100ProjectInvoking()
{
    //ctor
}

T100ProjectInvoking::~T100ProjectInvoking()
{
    //dtor
}

T100VOID T100ProjectInvoking::Init(T100ProjectFrame* frame)
{
    m_application       = T100NEW T100ProjectApplication();

    m_application->Create(frame);
}

T100VOID T100ProjectInvoking::Uninit()
{
    m_application->Destroy();

    T100SAFE_DELETE(m_application);
}

T100VOID T100ProjectInvoking::OnMainMenu(wxCommandEvent& event)
{
    m_application->SendEvent(event);
}

T100VOID T100ProjectInvoking::OnQuit()
{
    m_application->Quit();
}
