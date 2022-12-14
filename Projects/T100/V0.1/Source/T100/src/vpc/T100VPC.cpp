#include "T100VPC.h"

#include "T100VPCServe.h"
#include "T100VPCView.h"
#include "T100VPCLink.h"
#include "T100VPCCallback.h"

#include "T100LogFile.h"
#include "T100LogConsole.h"

#include "T100VPCApp.h"


namespace T100VPC{

T100VPC::T100VPC(T100VPCApp* app)
    :m_app(app)
{
    //ctor
    init();
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

    T100VPCLink::init(m_serve, m_view);
    T100VPCCallback::init(m_serve, m_view);
}

T100VOID T100VPC::destroy()
{
    T100SAFE_DELETE(m_view);
    T100SAFE_DELETE(m_serve);
}

T100VOID T100VPC::init()
{
    T100WSTRING         file;

    file    = L"logs\\vpc.log";

    if(!T100VPCLog::running()){
        T100VPCLog::append(T100NEW T100Library::T100LogConsole());
        T100VPCLog::append(T100NEW T100Library::T100LogFile(file));

        T100VPCLog::start();
    }
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

T100BOOL T100VPC::show()
{
    if(m_view){
        return m_view->show();
    }
    return T100FALSE;
}

T100VOID T100VPC::quit()
{
    if(m_view){
        m_view->quit();
    }

    if(m_app){
        m_app->quit();
    }
}

T100BOOL T100VPC::run()
{
    if(m_view){
        return m_view->run();
    }
    return T100FALSE;
}

T100WORD T100VPC::getReturn()
{
    if(m_serve){
        return m_serve->getReturn();
    }
    return 0;
}

}
