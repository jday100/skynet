#include "T100VPC.h"

#include "T100VPCServe.h"
#include "T100VPCView.h"
#include "T100VPCCallback.h"


namespace T100VPC{

T100VPC::T100VPC()
{
    //ctor
    create();
}

T100VPC::~T100VPC()
{
    //dtor
    destroy();
}

T100VOID T100VPC::create()
{
    m_serve     = T100NEW T100VPCServe();
    m_view      = T100NEW T100VPCView();

    T100VPCCallback::init(m_serve, m_view);
}

T100VOID T100VPC::destroy()
{
    T100SAFE_DELETE(m_view);
    T100SAFE_DELETE(m_serve);
}

T100VOID T100VPC::setServe(T100VPCServe* serve)
{
    m_serve = serve;
}

T100VPCServe* T100VPC::getServe()
{
    return m_serve;
}

T100VOID T100VPC::setView(T100VPCView* view)
{
    m_view = view;
}

T100VPCView* T100VPC::getView()
{
    return m_view;
}

T100VOID T100VPC::show()
{
    if(m_view){
        m_view->show();
    }
}

T100VOID T100VPC::quit()
{
    if(m_view){
        m_view->quit();
    }
}

T100BOOL T100VPC::run()
{
    if(m_view){
        return m_view->run();
    }
    return T100FALSE;
}

}
