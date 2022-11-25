#include "T100VPCApp.h"

#include "T100VPCServe.h"
#include "T100VPCView.h"
#include "T100VPCCallback.h"

namespace T100VPC{

T100VPCApp::T100VPCApp(T100ThisAppManager* obj)
    :T100Library::T100AppBase(obj)
{
    //ctor
    create();
}

T100VPCApp::~T100VPCApp()
{
    //dtor
    destroy();
}

T100VOID T100VPCApp::create()
{
    m_serve     = T100NEW T100VPCServe();
    m_view      = T100NEW T100VPCView();

    T100VPCCallback::init(m_serve, m_view);
}

T100VOID T100VPCApp::destroy()
{
    T100SAFE_DELETE(m_view);
    T100SAFE_DELETE(m_serve);
}

T100VOID T100VPCApp::setServe(T100VPCServe* serve)
{
    m_serve = serve;
}

T100VPCServe* T100VPCApp::getServe()
{
    return m_serve;
}

T100VOID T100VPCApp::setView(T100VPCView* view)
{
    m_view = view;
}

T100VPCView* T100VPCApp::getView()
{
    return m_view;
}

T100BOOL T100VPCApp::show()
{
    if(!m_view){
        return T100FALSE;
    }

    return m_view->show();
}

}
