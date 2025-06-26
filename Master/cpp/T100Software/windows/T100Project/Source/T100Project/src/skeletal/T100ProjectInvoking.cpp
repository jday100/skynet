#include "T100ProjectInvoking.h"

#include "T100AllExtensions.h"
#include "T100ProjectApplication.h"

T100ProjectApplication*         T100ProjectInvoking::m_application          = T100NULL;

T100ProjectInvoking::T100ProjectInvoking()
{
    //ctor
}

T100ProjectInvoking::~T100ProjectInvoking()
{
    //dtor
}

T100VOID T100ProjectInvoking::Create(T100ProjectApplication* application)
{
    m_application   = application;
}

T100VOID T100ProjectInvoking::Destroy()
{

}

T100VOID T100ProjectInvoking::BindMenu(const T100WSTRING& label, T100UINT value, T100EVENT_FUNCTION call, T100EventHandler* handler)
{
    if(!m_application){
        return;
    }
    m_application->GetSkeletal().GetExtendedManager().Append(T100PROJECT_VIEW_MAIN_MENU, value, label);
    m_application->GetSkeletal().GetExtendedManager().ConnectMenu(label, value, m_application->GetFrame(), call, handler);
}

T100VOID T100ProjectInvoking::CallMenu(const T100WSTRING& label, T100MenuEvent* event)
{
    if(!m_application){
        return;
    }
    m_application->GetSkeletal().GetExtendedManager().SendMenu(label, *event);
}

T100VOID T100ProjectInvoking::OnMainMenu(T100MenuEvent& event)
{
    m_application->GetSkeletal().GetExtendedManager().FindMenu(T100PROJECT_VIEW_MAIN_MENU, event);
}

T100VOID T100ProjectInvoking::OnResize(T100WindowEvent& event)
{
    m_application->GetSkeletal().GetExtendedManager().SendEvent(T100PROJECT_VIEW_MAIN_FRAME_RESIZE, event);
}

T100VOID T100ProjectInvoking::Quit()
{
    m_application->GetSkeletal().Quit();
}
