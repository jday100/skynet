#include "T100FontApp.h"

#include "T100FontServe.h"
#include "T100FontView.h"
#include "T100FontCallback.h"


namespace T100FontBuilder{

T100FontApp::T100FontApp(T100ThisAppManager* obj)
    :T100WxWidgets::T100WxApp((T100WxWidgets::T100WxAppManager*)obj)
{
    //ctor
    create();
}

T100FontApp::~T100FontApp()
{
    //dtor
    destroy();
}

T100VOID T100FontApp::create()
{
    m_serve     = T100NEW T100FontServe();
    m_view      = T100NEW T100FontView();

    T100FontCallback::init(m_serve, m_view);

    m_view->init();
}

T100VOID T100FontApp::destroy()
{
    T100SAFE_DELETE(m_view);
    T100SAFE_DELETE(m_serve);
}

T100VOID T100FontApp::setServe(T100FontServe* serve)
{
    m_serve = serve;
}

T100FontServe* T100FontApp::getServe()
{
    return m_serve;
}

T100VOID T100FontApp::setView(T100FontView* view)
{
    m_view = view;
}

T100FontView* T100FontApp::getView()
{
    return m_view;
}

T100VOID T100FontApp::show()
{
    if(m_view){
        m_view->show();
    }
}

}
